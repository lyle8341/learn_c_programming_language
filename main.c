#include <stdio.h>

#include "io.h"
#include "op_exp/op_exp.h"
#include "position.h"
#include "array/one_dimension/array.h"
#include "array/two_dimension/2d_array.h"
#include "pointer/ptr.h"


int main() {

    int b[4] = {12, 22, 32, 42};
    int a[4];

    a[4] = 100;
    printf("b[0] = %d\n", b[0]);


    //         mov     DWORD PTR [rbp-16], 12
    //        mov     DWORD PTR [rbp-12], 22
    //        mov     DWORD PTR [rbp-8], 32
    //        mov     DWORD PTR [rbp-4], 42
    return 0;
}
