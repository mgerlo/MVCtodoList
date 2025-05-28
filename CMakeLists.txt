cmake_minimum_required(VERSION 3.21)
project(todoList)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(test)

set(SOURCE_FILES
        Model.cpp Model.h
        View.cpp View.h
        ToDoListView.cpp ToDoListView.h
        Subject.h Observer.h AbstractController.h
        Controller.cpp Controller.h
        TodoList.cpp TodoList.h
        Task.cpp Task.h)
add_executable(todoList main.cpp ${SOURCE_FILES})
add_library(core ${SOURCE_FILES})
target_link_libraries(todoList core)

# Librerie wxWidgets necessarie
find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})
target_link_libraries(todoList ${wxWidgets_LIBRARIES})
