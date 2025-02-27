cmake_minimum_required(VERSION 3.21)
project(todoList)

set(CMAKE_CXX_STANDARD 11)

add_executable(todoList main.cpp
        Model.cpp
        Model.h
        ToDoListView.cpp
        ToDoListView.h
        Subject.h
        Observer.h
        Controller.cpp
        Controller.h
        AbstractController.h)
