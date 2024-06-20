//
// Created by 李玉龙 on 2024/6/20.
//

#include "2d_array.h"
#include <stdio.h>

// arr[行][列]
// arr[x][y] 可以理解为x个一维数组

void setValue() {
    //分段赋值
    int a[3][4] = {{1, 2,  3,  4},
                   {5, 6,  7,  8},
                   {9, 10, 11, 12}
    };

    //连续赋值
    int b[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    //部分赋值，未初始化则为0
    int c[3][4] = {1, 2, 3, 4};

    //0值初始化，所有的成员都设置为0
    int d[3][4] = {0};

    //不指定行数，定义时必须初始化
    int e[][4] = {1, 2, 3, 4, 5, 6, 7, 8};

    //列必须指定！！！！

    printf("a数组的大小为：%d\n", sizeof(a));
}

void structInMemory() {
    int a[3][4] = {{1, 2,  3,  4},
                   {5, 6,  7,  8},
                   {9, 10, 11, 12}
    };

    for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i) {//行
        for (int j = 0; j < sizeof(a[0]) / sizeof(a[0][0]); ++j) {//列
            printf("a[%d][%d]: %d addr:%p\t", i, j, a[i][j], &a[i][j]);
        }
        printf("\n");
    }


}