#include "gtest/gtest.h"

#include "../Model.h"

TEST(Model, ListsNumber) {
    TodoList l1;
    l1.addTask(Task("Start"));
    l1.addTask(Task("Example"));
    TodoList l2;
    l2.addTask(Task("0"));
    l2.addTask(Task("Activity 2"));
    l2.addTask(Task("Activity 3"));
    l2.addTask(Task("Activity 4"));
    TodoList l3;
    l3.addTask(Task("Activity 1"));
    Model m;
    EXPECT_EQ(0, m.getLists().size()) << "Empty (starting) list's size should be 0";
    m.addList(l1);
    EXPECT_EQ(1, m.getLists().size()) << "Something wrong incrementing Lists' Number";
    m.addList(l2);
    m.addList(l3);
    EXPECT_EQ(3, m.getLists().size()) << "Something wrong incrementing Lists' Number";
}
