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

+ 野指针
  > 未被初始化的指针

+ 空指针
  > 被赋值为NULL的指针，它不指向任何的对象或者函数  
  > 空指针不能直接使用，赋值空指针目的是判断，然后再操作

+ 万能指针
  + void *
  + 可以指向任何地址
    ```c
    int apge = 37;
    void *p = &age;
    ```
  + 可以隐式自动转化为其它类型指针
    ```c
    int *pi = p;
    ```
  + 不能对void *取值操作，因为它没有类型，或者说不能判断存储的是什么类型
    ```c
    printf("%d\n", *p); //error
    printf("%d\n", *(int *)p);//right
    ```


### typedef
+ typedef 类型 别名
  + typedef int INT; //INT 就是我们定义的新类型，代替int
  + typedef void (*PFUNA)(int a);//PFUNA就是我们定义的新类型

- typedef的一个重要用途是定义机器无关的类型
  - typedef long double Real;
  - typedef double Real;
  - typedef float Real;

- typedef 为现有类型创建别名
  - typedef unsigned int UInt32;
  - typedef int IntArray[10];
    - IntArray arr;


### 数组
+ 数组名表示数组首元素的地址，因此数组名也是一种指针
+ 比如数组arr
  + arr表示首元素地址
  + &arr表示整个数组的首地址
  + arr和&arr值相同，但是意义不同，arr+1表示第二个元素的地址；&arr+1表示整个数组长度后的地址

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

### 数组指针
```c
int main(int argc, char *argv[]) {
    int ages[] = {23, 45, 76, 90};
    int *p = ages; //一维数组指针
    for (int i = 0; i < sizeof(ages) / sizeof(ages[0]); ++i) {
        printf("*(p+%d): %d\n", i, *(p + i));
    }
    for (int i = 0; i < sizeof(ages) / sizeof(ages[0]); ++i) {
        printf("ages[%d]: %d\n", i, ages[i]);
    }
    return 0;
}
```
```c
int main(int argc, char *argv[]) {
    int arr[3][2] = {
            {1, 3},
            {5, 2},
            {7, 4}
    };
    int (*p)[2] = arr; //二维数组指针，2是列
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
//            printf("%d\t", arr[i][j]);
//            printf("%d\t", p[i][j]);
//            printf("%d\t", *(*(arr + i) + j)); //3️⃣
            /**
             * 第三部3️⃣的演变过程
             * printf("%d\t", arr[i][j]);
             * printf("%d\t", *(arr[i] + j));
             * printf("%d\t", *(*(arr + i) + j));
            */
        }
        printf("\n");
    }
    return 0;
}
```
```c
//用一维数组的方式访问二维数组
    int *parr = arr;//arr是二维数组
    for (int i = 0; i < row * column; ++i) {
        printf("%d ", parr[i]);
    }
```

### 指针数组

### 指针函数
> 返回指针的函数

+ 不要返回临时变量的地址
+ 可以返回动态申请的空间的地址
+ 可以返回静态变量的地址

### 函数指针
> 如果在程序中定义了一个函数，那么在运行时系统就会为这个函数代码分配一段存储空间这段存储空间的首地址称为这个函数的地址，
> 而且函数名表示的就是这个地址，既然是地址我们就可以定义一个变量来存放，这个指针变量就叫做函数指针变量，简称函数指针

+ 函数指针定义
  + **函数返回值类型 (\* 指针变量名) (函数参数列表)**




## 优先级


### 内存四区/存储类别
+ 存储类别
  + 自动型 auto
    + (auto) int age = 18
    + 编译器自动回收变量的内存
  + 静态型 static
    + 在程序运行期间只初始化一次，不随作用域的结束而销毁
    + 生命周期从创建开始到程序执行结束
    + 静态变量和全局变量一样，会自动初始化为0
    + 改变生命周期｜限定访问范围
  + 寄存器 register
    + 变量存储在寄存器中
    + 此时不能对变量取地址
    + for循环时候编译器会做这种优化
  + 外部型 extern
    + 全局变量默认就是extern的，如果不想让全局变量在别的文件里面被访问，那么使用static修饰


```c
 int age = 10; ===> auto int age = 10;

```



### 反汇编

> 1. brew install binutils

> 2. objdump -dS main