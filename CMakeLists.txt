cmake_minimum_required(VERSION 4.0)
project(CppGameEngine)

set(CMAKE_CXX_STANDARD 20)

add_executable(CppGameEngine main.cpp
        MyGameEngine.h
        FreeSquare.h
        KeyManager.h
        Ballet.h
        TestObject.h)
