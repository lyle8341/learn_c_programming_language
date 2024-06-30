cmake_minimum_required(VERSION 3.20.2)
#cmake_minimum_required(VERSION 3.28)

project(learn_c_programming_language C)

set(CMAKE_C_STANDARD 99)

add_executable(learn_c_programming_language main.c io.c
        io.h
        op_exp/op_exp.c
        op_exp/op_exp.h
        position.c
        position.h
        array/one_dimension/array.c
        array/one_dimension/array.h
        array/two_dimension/2d_array.c
        array/two_dimension/2d_array.h
        pointer/ptr.c
        pointer/ptr.h
        string/string.c
        string/string.h)
