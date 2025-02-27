cmake_minimum_required(VERSION 3.21)
project(todoList)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(test)

set(SOURCE_FILES Model.cpp Model.h ToDoListView.cpp ToDoListView.h Subject.h Observer.h Controller.cpp Controller.h AbstractController.h TodoList.cpp TodoList.h Task.cpp Task.h)
add_executable(todoList main.cpp Model.cpp Model.h ToDoListView.cpp ToDoListView.h Subject.h Observer.h Controller.cpp Controller.h AbstractController.h TodoList.cpp TodoList.h Task.cpp Task.h)
add_library(core ${SOURCE_FILES})
target_link_libraries(todoList core)
