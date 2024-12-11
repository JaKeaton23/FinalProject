# FinalProject

Data Structure Visualization Project

Overview

This project is a comprehensive implementation and visualization of various data structures, including AVL Trees, Binary Search Trees (BST), B-Trees, Red-Black Trees, Heaps, Priority Queues, Stacks, and Queues. It also features a GUI to visualize these structures using the SFML (Simple and Fast Multimedia Library) framework.

Repository Structure on GitHub

DataStructuresProject/
|—— src/
|   |—— Heap.cpp
|   |—— BST.cpp
|   |—— AVL.cpp
|   |—— RedBlack.cpp
|   |—— BTree.cpp
|   |—— GUIManager.cpp
|   —— main.cpp
|—— include/
|   |—— Heap.h
|   |—— BST.h
|   |—— AVL.h
|   |—— RedBlack.h
|   |—— BTree.h
|   —— GUIManager.h
|—— assets/
|   —— fonts/
|—— CMakeLists.txt
|—— README.md
—— LICENSE

Overview

This project is a comprehensive implementation and visualization of various data structures, including AVL Trees, Binary Search Trees (BST), B-Trees, Red-Black Trees, Heaps, Priority Queues, Stacks, and Queues. It also features a GUI to visualize these structures using the SFML (Simple and Fast Multimedia Library) framework.

Features

AVL Tree: Balanced binary search tree with insert, delete, and search operations.

Binary Search Tree (BST): Standard binary search tree with basic operations.

B-Tree: Self-balancing tree used for database systems and file systems.

Red-Black Tree: Balanced binary search tree with color-coded nodes.

Heap: Binary heap implementation with insert and delete operations.

Priority Queue: A queue implemented using a binary heap with customizable priority.

Stack and Queue: Basic stack and queue implementations using deque.

GUI Visualization: Interactive visualization for the implemented data structures using SFML.

Prerequisites

C++ Compiler: Ensure you have a C++17 or later compiler installed.

SFML Library: Download and install the SFML library from SFML's website.

CMake (optional): For building the project using a CMake configuration.

Font File: Include a font file (e.g., arial.ttf) in the project directory for text rendering.

Build Instructions

Clone the repository:

git clone <repository-url>
cd <repository-folder>

Compile the project using your preferred method:

Command Line:

g++ -o main main.cpp GUIManager.cpp HeapVisualizer.cpp Heap.cpp BST.cpp AVL.cpp BTree.cpp RedBlack.cpp PriorityQueue.cpp StackQueue.cpp -lsfml-graphics -lsfml-window -lsfml-system

CMake:
Create a CMakeLists.txt file and use CMake to generate and build the project files.

Run the executable:

./main

Usage

Launch the application by running the executable.

Interact with the graphical interface to visualize data structure operations:

Insert, delete, and search elements in the data structures.

Observe real-time updates and animations for the structures.

Customization

Modify the HeapVisualizer, GUIManager, or other visualization components to add or change features.

Adjust tree parameters in their respective header files (e.g., t value in BTree.h for B-Tree degree).

Dependencies

SFML: Used for graphics and window management.

Standard C++ Libraries: For implementing data structures.

Contributing

Fork the repository.

Create a new branch for your feature or bug fix.

Submit a pull request with a detailed explanation of your changes.

Authors

Jayden Keaton (Primary Developer)

License

This project is licensed under the MIT License. See the LICENSE file for details.

Contact

For questions or feedback, contact Jayden Keaton.
