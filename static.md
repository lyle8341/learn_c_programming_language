
```c
#include <unistd.h> ////Header file for sleep(). man 3 sleep for details.
#include <stdio.h>
#include <pthread.h>

//create a global variable to change it in threads
int g = 0;

void *myThreadFun(void *vargp) {
    //store the value argument passed to this thread
    int myId = getpid();
    static int s = 0;
    ++s;
    ++g;
    printf("Thread ID: %d, Static: %d, Global: %d\n", myId, ++s, ++g);
    return NULL;
}

int main() {
    pthread_t tid;
    for (int i = 0; i < 3; ++i) {
        pthread_create(&tid, NULL, myThreadFun, NULL);
    }
    pthread_exit(NULL);
    return 0;
}
```