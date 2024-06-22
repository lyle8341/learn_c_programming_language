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