//
// Created by 李玉龙 on 2024/6/25.
//

#include "string.h"
#include <stdio.h>


//1.c语言中没有字符串类型。用一片内存空间保存一串字符，这片空间称作为字符数组
//2.以'\0'结尾的‘字符数组’被称为‘字符串数组’。'\0'是字符串结束的标志
//3.用双引号括起来的都是字符串
void string() {
    char str0[6] = {'h', 'e', 'l', 'l', 'o', '\0'};//字符串数组
    char str1[6] = "hello"; //简化版写法
    char str2[6] = {'h', 'e', 'l', 'l', 'o'};//str2[5]自动赋值为'\0'
    char str3[10] = {'h', 'e'};//其余八个元素自动赋值为'\0'
    char str4[] = "hello";//元素个数可以省略 数组分配空间大小为字符串中实际赋值字节数6
    char *str = "hello";//str是指针 存储字符串首地址 指向字符串

    char str7[5] = {'h', 'e', 'l', 'l', 'o'};//是字符数组而不是字符串数组，因为没有’\0’


    printf("str1: %zu\n", sizeof(str1));
    printf("str4: %zu\n", sizeof(str4));
    printf("str7: %zu\n", sizeof(str7));

//  char *a[] = {"123", "456", "abc", "ABC"}, **p = a;
    char *a[] = {"123", "456", "abc", "ABC"};
    char **p = a;

    printf("%c %c \n", a[2][2], p[2][2]);
    printf("%d %d \n", sizeof(a), sizeof(p));
}