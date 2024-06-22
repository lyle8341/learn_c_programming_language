#include <stdio.h>

#include "io.h"
#include "op_exp/op_exp.h"
#include "position.h"
#include "array/one_dimension/array.h"
#include "array/two_dimension/2d_array.h"
#include "pointer/ptr.h"


int main() {

    //array_ptr();

    int a = 90;

    printf("%p\n", a);
    printf("%p\n", &a);

    return 0;
}
