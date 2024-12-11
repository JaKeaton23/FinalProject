cmake_minimum_required(VERSION 3.29)
project(FinalProject)

set(CMAKE_CXX_STANDARD 20)

add_executable(FinalProject main.cpp
        AVL.h
        HeapVisualizer.h
        RedBlack.cpp
        BTree.cpp
        PriorityQueue.cpp
        StackQueue.cpp
        GUIManager.cpp)
