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

TEST(List, getTasks) {
    TodoList l;
    l.addTask(Task());
    l.addTask(Task("1", "01-01-2025", "21:00", 1, true));
    l.addTask(Task("2", "01-01-2025", "21:00", 1, true));
    l.addTask(Task("3"));
    l.addTask(Task("4", "01-01-2025", "21:00", 1, true));
    list<Task> d = l.getNotDone();
    EXPECT_EQ(2, d.size());
    list<Task> n = l.getDone();
    EXPECT_EQ(3, n.size());
}
