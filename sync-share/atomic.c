#include <pthread.h>
#include <stdio.h>
#include <string.h>

_Atomic int a;

void *sum1() {
    for (int i = 0; i < 10000000; ++i) {
        a++;
    }
    return NULL;
}

void test1() {
    a = 0;
    pthread_t t1, t2;
    pthread_create(&t1, NULL, sum1, NULL);
    pthread_create(&t2, NULL, sum1, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("a = %d\n", a);
}

//
// 命令行单独编译运行
// gcc sync-share/atomic.c -DTEMP_OUT -lpthread -o atomic
//
#ifdef TEMP_OUT
int main(){
    test1();
}
#endif