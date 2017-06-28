cmake_minimum_required(VERSION 3.7)
project(rizk_hw3)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp ArgumentManager.h BinaryTree.h Node.h)
add_executable(rizk_hw3 ${SOURCE_FILES})