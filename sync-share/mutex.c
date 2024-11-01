#include <pthread.h>
#include <stdio.h>

int a;
pthread_mutex_t mutex;

void *sum() {
    for (int i = 0; i < 10000000; ++i) {
        pthread_mutex_lock(&mutex);
        a++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void test() {
    a = 0;
    pthread_t t1, t2;
    pthread_create(&t1, NULL, sum, NULL);
    pthread_create(&t2, NULL, sum, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("a = %d\n", a);
}

//
// 命令行单独编译运行
//  gcc sync-share/mutex.c -DTEMP_OUT -lpthread -o mutex
//
#ifdef TEMP_OUT
int main() {
    pthread_mutex_init(&mutex, NULL);
    test();
}
#endif