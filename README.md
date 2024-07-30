# 学习C语言

+ C程序的基本组成结构
  + 源文件
    + 后缀为.c
    + 实现程序功能
  + 头文件
    + 后缀为.h
    + 使用方式
      ```
      #include "main.h"
      ```
    + 函数声明｜全局变量的声明｜宏定义｜类型的声明
  + 一个C语言所组成的项目中只允许有一个main函数

### include<>和" "区别
> 编译器在编译的时候，如果为" ",编译器会先检查本工程目录下" "内对应的文件，
> 如果该文件不存在，继续检索，系统的头文件目录（标准C安装的目录），如果是<>，编译器
> 只会去系统头文件目录下检索




### 整形常量
```shell
10          代表int类型
10L         代表long类型
10LL        代表long long类型
10U         代表unsigned int类型
10UL        代表unsigned long类型
10ULL       代表unsigned long long类型
```

### 整形数据的打印格式
```
======d结尾
%hd     输出short类型
%d      输出int类型
%ld     输出long类型
%lld    输出long long类型
======u结尾
%hu     输出unsigned short类型
%u      输出unsigned int类型
%lu     输出unsigned long类型
%llu    输出unsigned long long类型
```



### 带宽
> 单位是Mb，注意是小写b，兆比特。转换为MB需要除以8


+ 预编译
  ```shell
  # -E            Only run the preprocessor
  # -o <file>      Write output to <file>
  gcc -E main.c -o main.i
  ```
  
+ 编译
  > gcc -o main main.c

  > gcc main.c -o main -DDEBUG #传参


## 指定入口函数
```
gcc -nostartfiles -efunc main.c
gcc -nostartfiles -e main program.c -o my_program

```

### 算数运算符
+ %取模运算符的两个操作数只能为整数


### 逻辑运算符
+ 逻辑真（关系成立）：非0
+ 逻辑假（关系不成立）：0


### 二维数组
> 在内存中并不存在二维数组，二维数组实际的硬件存储是连续编址的，也就是说内存中只有一维数组
> ，即放完一行之后顺次放入第二行，和一维数组存放方式是一样的



### 函数参数
+ 函数调用时，将实参的值赋值给形参
+ 形参只有在函数被调用时才会被分配内存空间（函数栈上分配）
+ 实参可以是常量、变量、表达式、函数名


### 局部变量
+ 定义在{}内的变量，称之为局部变量


### 全局变量
+ 全局变量如果没有被初始化，会被默认初始化为0

### 预处理
+ #号开头的命令称为**预处理命令**
+ 宏定义、文件包含、条件编译等

### 宏定义
+ 注意用括号
  ```
  #define max(a, b) (a)>(b)?(a):(b)
  #define F(x) (x)*(x)*(x)
  ```
+ 无参宏定义
  > #define PI 3.14


### 条件编译
```
#if         如果条件为真，则执行相应操作
#elif       
#else
#endif      结束相应的条件编译指令
#ifdef      如果该宏已定义，则执行相应操作
#ifndef     如果该宏没有定义，则执行相应操作
```

### 指针
+ 空指针的作用是防止指针变量变成野指针。
+ 指针变量+n，指针往后偏移了n个数据（不是字节）

### 数组
+ 数组名表示数组的首地址，因此数组名也是一种指针

![array pointer](images/数组_指针.jpg)

![数组栈上分配](images/数组栈上分配.png)


# 字符串
![字符串指针](images/字符串指针.png)

1.输出
```c
    char *str = "hello";
    printf("%s\n", str);
    printf("%c\n", *str);
```

### free字符串常量（非法）
```c
char *StrConst() {
    char *p = "zhangsan lisi wangwu zhaoliu";
    return p;
}
//调用
char *p = StrConst();
printf("%s\n", p);
free(p); // pointer being freed was not allocated
```
+ **free不能重复调用**


> 1.p指向在函数体中申请的堆空间的首址
  + ![二级指针传参](images/二级指针传参.jpg)
  + ![一级指针传参](images/一级指针传参.jpg)

### [char str[] = "hello world"; 编译器做了什么](https://blog.csdn.net/weixin_44200553/article/details/137482838)

## C 源文件被编译成可执行程序总共需要四步

> 假设源文件叫 main.c。

```
1）预处理：gcc -E main.c -o main.i，根据 C 源文件得到预处理之后的文件。这一步只是对 main.c 进行了预处理，比如宏定义展开、头文件展开、条件编译等等，同时将代码中的注释删除，注意：这一步并不会检查语法；
2）编译：gcc -S main.i -o main.s，将预处理后的文件进行编译、生成汇编文件，这一步会进行语法检测、变量的内存分配等等；
3）汇编：gcc -c main.s -o main.o，根据汇编文件生成目标文件；
4）链接：gcc main.o -o main.exe，程序是需要依赖各种库的，可以是静态库也可以是动态库，因此需要将目标文件和其引用的库链接在一起，最终才能构成可执行的二进制文件；
```








### 反汇编

> 1. brew install binutils

> 2. objdump -dS main