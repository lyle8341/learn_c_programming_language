# 系统调用(以下程序都需要在linux上运行)

+ 字符串转十六进制
> printf 'HiWorld\n'| xxd -p|fold -w2|tac|tr -d "\n"|awk '{print "0x"$0}'   

+ 特殊情况转换（超过寄存器大小）
  + printf "%s\n" 'hello, lyle!'| xxd -p|fold -w2|tac|tr -d "\n"|awk '{print "0x"$0}'
  + 寄存器64bit，只能放八个字符
  + 使用%s是兼容感叹号等特殊符号，目标字符串中的换行\n放到%s后面了

+ 创建一个Hello world的c程序
```c
#include <stdio.h>

int main() {
    printf("HiWorld\n");
    return 0;
}
```
+ 编译
  + ```shell
    lrwxrwxrwx 1 root root 3 6月   6 23:27 /usr/bin/cc -> gcc
    ```
  + ```shell
    [root@sun syscall]# cc syscall.c
    ```
+ strace
  + ```shell
    [root@sun syscall]# strace -e trace=write ./a.out > /dev/null
    write(1, "HiWorld\n", 8)          = 8
    +++ exited with 0 +++
    ```
    
+ 逐步替换上述c代码
  + 1. ```c
       #include <unistd.h>
       int main() {
           write(1, "HiWorld\n", 8);
       }
       ```
  + 2. ```c
       #include <unistd.h>
       #include <sys/syscall.h>
       int main(void) {
           syscall(SYS_write, 1, "HiWorld\n", 8);
           return 0;
       }
       ``` 
    + 求SYS_write的值
      + ```c
        // On Linux x86-64, this prints 1. On macOS, it prints 4
        #include <stdio.h>
        #include <sys/syscall.h>
        int main(void) {
            printf("%d\n", SYS_write);
            return 0;
        }
        ```
  + 3. [查看系统调用函数的汇编代码](https://github.com/bminor/glibc/blob/9a123ff05d624f429aa31fce10a8276a52a11f0d/sysdeps/unix/sysv/linux/x86_64/syscall.S)
       ```asm
         .text
         ENTRY (syscall)
         movq %rdi, %rax		/* Syscall number -> rax.  */
         movq %rsi, %rdi		/* shift arg1 - arg5.  */
         movq %rdx, %rsi
         movq %rcx, %rdx
         movq %r8, %r10
         movq %r9, %r8
         movq 8(%rsp),%r9	/* arg6 is on the stack.  */
         syscall			/* Do the system call.  */
         cmpq $-4095, %rax	/* Check %rax for error.  */
         jae SYSCALL_ERROR_LABEL	/* Jump to error handler if error.  */
         ret			/* Return to caller.  */
       
       PSEUDO_END (syscall)
       ```
  + 4. GCC内联汇编在C中自己完成此操作
    ```c
    int main(void) {
        //syscall(SYS_write, 1, "HiWorld\n", 8);
        register int syscall_no asm("rax") = 1;
        register int arg1       asm("rdi") = 1;
        register char *arg2     asm("rsi") = "HiWorld\n";
        register int arg3       asm("rdx") = 8;
        asm("syscall");
        return 0;
    }
    ```
  + 5. 使用汇编方式
    ```asm
    section .text
      global _start
        _start:
          ; syscall(SYS_write, 1, "HiWorld\n", 8);
          mov rax, 1 ;Syscall number -> rax
          mov rdi, 1 ;arg1 Filehandle
          ; arg2放入rsi寄存器(把字符串写入堆栈内存，并把内存地址传给rsi)------ start
          mov rbx, 0x0a646c726f576948
          push rbx
          mov rsi, rsp
          ; ------ end
          mov rdx, 8 ;arg3 MaxCharCount
          syscall
    
          mov rax, 60 ;exit
          syscall
    ```
    > nasm -f elf64 syscall.s && ld syscall.o
    
    > ./a.out

+ 参考文档
  + [How to make a system call in C](https://jameshfisher.com/2018/02/19/how-to-syscall-in-c/)