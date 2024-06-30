#include <stdio.h>

#include "io.h"
#include "op_exp/op_exp.h"
#include "position.h"
#include "array/one_dimension/array.h"
#include "array/two_dimension/2d_array.h"
#include "pointer/ptr.h"
#include <stdlib.h>
#include <string.h>

char *getMemory(void) {
    char p[] = "hello world";
    return p;
}

int main() {
    char x = 'h';
    printf("%d\n", x);

    return 0;
}