//
// Created by 李玉龙 on 2024/6/18.
//
#include <stdio.h>
#include "io.h"


void io() {
    char y;
    scanf("%c", &y);//只能捕获一个字符
    printf("y: %c\n", y);
    //从屏幕读取下一个可用的字符，并把它返回为一个整数
    int result = getchar();
    printf("getchar: %d\n", result);

    char x;
    scanf("%c", &x);//只能捕获一个字符
    printf("x: %c\n", x);



//    int a, b;
//    scanf("%d %d", &a, &b);
//    printf("a: %d b: %d", a, b);
}