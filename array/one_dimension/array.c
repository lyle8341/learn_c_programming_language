//
// Created by 李玉龙 on 2024/6/19.
//
#include <stdio.h>
#include "array.h"

void arrayTest() {
    int a[4];
    for (int i = 0; i < 4; i++)
        a[i] = 10 + i;

    for (int i = 0; i < 4; i++)
        printf("%d\t", a[i]);
}

/*
 *
 */
void initArray() {
    //定义一个数组，同时初始化所有成员变量
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //初始化前三个成员，后面所有元素都设置位0
    int b[10] = {1, 2, 3};
    //所有成员都设置位0
    int c[10] = {0};
    //[]中不定义元素个数，定义时必须初始化
    int d[] = {1, 2, 3, 4, 5};
}

void addressOfArrayElement() {
//    char array[] = {'A', 'B', 'C', 'D'};
    int array[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
        printf("%p\n", &array[i]);
}