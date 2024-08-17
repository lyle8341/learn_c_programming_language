#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

/**
 *
 * @param time 秒
 */
void timer(long time) {
    clock_t start;
    start = clock();
    while (1) {
        if ((clock() - start) >= (time * CLOCKS_PER_SEC)) {
            break;
        }
    }
}


int main() {

    for (int i = 0; i < 10; ++i) {
        timer(1);
        printf("%d\n", i);
    }
    getchar();
    return 0;
}