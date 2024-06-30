//
// Created by 李玉龙 on 2024/6/21.
//

#include "ptr.h"
#include <stdio.h>

/**
 * In “%zu” format, z is a length modifier and u stand for unsigned type.
 */
void ptr_size() {
    printf("int *:\t\t\t%zu\n", sizeof(int *));
    printf("char *:\t\t\t%zu\n", sizeof(char *));
    printf("float *:\t\t%zu\n", sizeof(float *));
    printf("double *:\t\t%zu\n", sizeof(double *));
    printf("long *:\t\t\t%zu\n", sizeof(long *));
    printf("long long *:\t%zu\n", sizeof(long long *));
}

void array_ptr() {
    int ch[] = {1, 2, 3, 4};
    //数组名，数组的首地址
    printf("ch: \t%p\n", ch);

    printf("&ch: \t%p\n", &ch);
}

void traverse() {
    int ch[] = {12, 21, 30, 45};

    for (int i = 0; i < sizeof(ch) / sizeof(ch[0]); ++i)
        printf("ch[%d]: = %d\n", i, ch[i]);

    for (int i = 0; i < sizeof(ch) / sizeof(ch[0]); ++i)
        printf("ch[%d]: = %d\n", i, *(ch + i));
}

void ptrArray() {
    int a = 10, b = 20, c = 30;
    int *p[3];
    p[0] = &a;
    p[1] = &b;
    p[2] = &c;

    for (int i = 0; i < 3; ++i) {
        printf("%d\n", **(p+i));
    }

}