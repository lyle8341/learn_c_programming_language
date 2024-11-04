#include <stdio.h>
#include <stdlib.h>

int func(int argc,char *argv[]){
    printf("参数的个数是(包括第0个当前可执行文件的名字)：%d, %s\n", argc, __FILE__);
    //参数列表，字符串指针
    while (*argv)
    {
        puts(*argv++);
    }
}