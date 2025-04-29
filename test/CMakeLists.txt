cmake_minimum_required(VERSION 3.21)

add_subdirectory(./lib/googletest-main/)
set(gtest_SOURCE_DIR, ./lib/googletest-main/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Files di test
set(TEST_SOURCE_FILES runAllTests.cpp ModelTest.cpp TaskTest.cpp TaskFixture.cpp ListTest.cpp)

# Eseguibile dei test
add_executable(todoListTests ${TEST_SOURCE_FILES})

# Link gtest, gtest_main con libreria core
target_link_libraries(todoListTests gtest gtest_main core)
