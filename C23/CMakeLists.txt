cmake_minimum_required(VERSION 3.17)
project(C23)

set(CMAKE_CXX_STANDARD 11)

add_executable(C23 main.cpp Exceptions.h Queue.h)