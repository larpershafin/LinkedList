cmake_minimum_required(VERSION 4.3)
project(untitled C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled
        linkedlist/linkedlist.c
        linkedlist/linkedlist.h
        linkedlist/main.c
)
