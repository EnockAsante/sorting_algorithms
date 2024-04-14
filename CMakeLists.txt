cmake_minimum_required(VERSION 3.27)
project(sorting_algorithms C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(sorting_algorithms
        0-bubble_sort.c
        print_array.c
        print_list.c
        sort.h
        1-insertion_sort_list.c)
