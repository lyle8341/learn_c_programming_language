//
// Created by 李玉龙 on 2024/6/19.
//
#include <stdio.h>

//输出日志定位
void position() {
    int x;
    scanf("%d", &x);
    printf("[%s %d] x: %d\n", __func__, __LINE__, x);
}