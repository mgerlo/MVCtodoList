#include "gtest/gtest.h"

#include "../Model.h"

TEST(Model, ListsNumber) {
    TodoList l1;
    l1.setTask(Task("Start"));
    l1.setTask(Task("Example"));
    TodoList l2;
    l2.setTask(Task());
    l2.setTask(Task("Activity 2"));
    l2.setTask(Task("Activity 3"));
    l2.setTask(Task("Activity 4"));
    TodoList l3;
    l3.setTask(Task("Activity 1"));
    Model m;
    m.setList(l1);
    m.setList(l2);
    m.setList(l3);
    EXPECT_EQ(3, m.getNum()) << "Something wrong incrementing Lists' Number";
}
