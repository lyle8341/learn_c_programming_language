#include <stdio.h>

// 整数 对应的二进制输出
struct Node {
    char name[10];
    short age;
    double money;
};
//最大的基本数据类型 double


int main() {
    struct Node n = {"wonderful", 37, 18.85};
    printf("结构体 - 首地址: %p\n", &n);
    printf("结构体 - 首元素: %p\n", &n.name);
    printf("结构体二元素地址: %p\n", &n.age);
    printf("结构体三元素地址: %p\n", &n.money);

    printf("%lu\n", sizeof(n));

    return 0;
}