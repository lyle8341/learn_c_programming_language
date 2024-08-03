#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {

    int *p = (int *) malloc(sizeof(int));
    *p = 56;

    printf("p:\t%p\n", p);
    printf("*p:\t%d\n", *p);


    free(p);

    return 0;
}