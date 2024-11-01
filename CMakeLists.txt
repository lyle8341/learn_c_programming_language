cmake_minimum_required(VERSION 3.20.2)
#cmake_minimum_required(VERSION 3.28)

project(learn_c_programming_language C)

set(CMAKE_C_STANDARD 99)


#搜索文件方式
#CMAKE_CURRENT_SOURCE_DIR 宏表示当前访问的CMakeLists.txt文件所在的路径

#方式一：
#[[
aux_source_directory(${PROJECT_SOURCE_DIR} SRC)
]]

#方式二：
# GLOB 将指定目录下搜索到的满足条件的所有文件名生成一个列表，并存储到变量中
# GLOB_RECURSE 递归搜索指定目录...

file(GLOB_RECURSE SRC ${PROJECT_SOURCE_DIR}/*.c)
#message(STATUS "搜索结果:\t${SRC}")

add_executable(learn_c_programming_language main.c
#        snake/v1.c
#        snake/v1.h
#        snake/v2.c
#        snake/v2.h
        define.hpp
        sync-share/atomic.c sync-share/mutex.c)

if(CMAKE_SYSTEM_NAME MATCHES "Darwin")
    list(APPEND SOURCES "snake/v1.c")
    list(APPEND SOURCES "snake/v1.h")
    list(APPEND SOURCES "snake/v2.c")
    list(APPEND SOURCES "snake/v2.h")
endif()

# 将源文件添加到可执行文件项目中
target_sources(learn_c_programming_language PRIVATE ${SOURCES})

#在本机查找依赖
if(CMAKE_SYSTEM_NAME MATCHES "Darwin")
    find_package(Curses REQUIRED) #查找Curses库
    message(STATUS "CURSES_INCLUDE_DIR:\t${CURSES_INCLUDE_DIR}")
    include_directories(${CURSES_INCLUDE_DIR}) #添加Curses库的头文件目录
    message(STATUS "CURSES_LIBRARY:\t${CURSES_LIBRARY}")
    target_link_libraries(learn_c_programming_language ${CURSES_LIBRARY}) #链接Curses库
endif()

if(CMAKE_SYSTEM_NAME MATCHES "Darwin")
    set(GCC_COVERAGE_COMPILE_FLAGS "-lncurses")
endif()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )
