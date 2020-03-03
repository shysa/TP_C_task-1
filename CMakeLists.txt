cmake_minimum_required(VERSION 3.10)
project(TP_C_task_1 C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-Wall -Werror -Wpedantic")

add_executable(TP_C_task_1 main.c)

add_library(lib STATIC functions.c)
target_link_libraries(TP_C_task_1 lib)


enable_testing()

add_subdirectory(tests)

