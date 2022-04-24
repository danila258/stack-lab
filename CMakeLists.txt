cmake_minimum_required(VERSION 3.22)
project(stack_lab)

set(CMAKE_CXX_STANDARD 14)

add_executable(stack_lab main.cpp Stack.cpp Stack.h StackImplementation.h)
