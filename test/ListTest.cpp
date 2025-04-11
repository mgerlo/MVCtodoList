#include "gtest/gtest.h"

#include "../TodoList.h"

TEST(List, countTotalTasks) {
    TodoList l;
    EXPECT_EQ(0, l.numTotTask());
    l.addTask(Task("first"));
    l.addTask(Task("second"));
    EXPECT_EQ(2, l.numTotTask());
    l.removeTask(Task("first"));
    EXPECT_EQ(1, l.numTotTask());
}
