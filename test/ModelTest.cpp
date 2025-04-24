#include "gtest/gtest.h"

#include "../Model.h"

TEST(Model, ListsNumber) {
    TodoList l1;
    l1.addTask(Task("Start", "0", "0"));
    l1.addTask(Task("Example", "0", "0"));
    TodoList l2;
    l2.addTask(Task("0", "0", "0"));
    l2.addTask(Task("Activity 2", "0", "0"));
    l2.addTask(Task("Activity 3", "0", "0"));
    l2.addTask(Task("Activity 4", "0", "0"));
    TodoList l3;
    l3.addTask(Task("Activity 1", "0", "0"));
    Model m;
    m.setList(l1);
    m.setList(l2);
    m.setList(l3);
    EXPECT_EQ(3, m.getNum()) << "Something wrong incrementing Lists' Number";
}
