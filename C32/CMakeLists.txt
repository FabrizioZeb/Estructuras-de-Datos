cmake_minimum_required(VERSION 3.17)
project(C32)

set(CMAKE_CXX_STANDARD 11)

add_executable(C32 main.cpp Exceptions.h Arbin.h List.h Queue.h)