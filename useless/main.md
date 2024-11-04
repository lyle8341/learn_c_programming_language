# 没有main函数如何运行

```c
#include <stdio.h>
#include <stdlib.h>

void func(){
    printf("Hello World\n");
    exit(0);
}
```

+ 编译命令(乱码解决参数)
  ```shell
  # -finput-charset=charset  表示源文件的编码方式, 默认以UTF-8来解析
  # -fexec-charset 指定多字节字符串(const char*)常量在编译后的程序里保存的编码集（若不指定，默认是UTF-8）
  # -fwide-exec-charset 指定宽字节字符串(const wchar_t*)常量在编译后的程序里的保存的编码集
  gcc -nostartfiles -efunc main.c -finput-charset=UTF-8 -fexec-charset=GBK
  ```

+ 结论
  + main函数与普通函数汇编指令一样

+ main函数参数输出
  ```c
  /**
   *
   * @param argc
   * @param argv 指针数组
   */
  int main(int argc, char *argv[]) {
      printf("参数的个数是(包括第0个当前可执行文件的名字)：%d, %s\n", argc, __FILE__);
      //参数列表，字符串指针
      while (*argv) {
          puts(*argv++);
          // puts(*(argv++));
      }
      exit(0);
  }
  ```

