#include "gtest/gtest.h"

#include "../TodoList.h"

TEST(List, CountTotalTasks) {
    TodoList l;
    EXPECT_EQ(0, l.numTotTask());
    l.addTask(Task("first"));
    l.addTask(Task("second"));
    EXPECT_EQ(2, l.numTotTask());
    l.removeTask(Task("first"));
    EXPECT_EQ(1, l.numTotTask());
}

TEST(List, GetTasks) {
    TodoList l;
    l.addTask(Task("0"));
    l.addTask(Task("1", "01-01-2025", "21:00", 1, true));
    l.addTask(Task("2", "01-01-2025", "21:00", 1, true));
    l.addTask(Task("3"));
    l.addTask(Task("4", "01-01-2025", "21:00", 1, true));
    list<Task> n = l.getNotDone();
    TodoList ln("ListNotDone", n);
    EXPECT_EQ(0, ln.numDone());
    EXPECT_EQ(2, ln.numNotDone());
    EXPECT_EQ("0", ln.getTasks().begin()->getDescription());
    EXPECT_EQ("3", ln.searchTask("3").begin()->getDescription());
    list<Task> d = l.getDone();
    TodoList ld("ListDone", d);
    EXPECT_EQ(3, ld.numDone());
    EXPECT_EQ(0, ld.numNotDone());
    EXPECT_EQ("1", ld.getTasks().begin()->getDescription());
    EXPECT_EQ("2", ld.searchTask("2").begin()->getDescription());
    EXPECT_EQ("4", ld.searchTask("4").begin()->getDescription());
}

TEST(List, NumTasksByDate) {
    TodoList l1("List1", {
            Task("0", "29-04-2025"),
            Task("1"),
            Task("2"),
            Task("3", "29-04-2025"),
            Task("4")
    });
    EXPECT_EQ(2, l1.numTaskDate("29-04-2025"));
    EXPECT_EQ(3, l1.numTaskDate("0"));
    l1.removeTask(Task("3", "29-04-2025"));
    l1.addTask(Task("5"));
    EXPECT_EQ(1, l1.numTaskDate("29-04-2025"));
    EXPECT_EQ(4, l1.numTaskDate("0"));
}

TEST(List, NumTasksByPriority) {
    TodoList p("Lista", {
            Task("0"),
            Task("1", "0", "0", 3),
            Task("2", "0", "0", 3),
            Task("3", "0", "0", 0),
            Task("4", "0", "0", 3)
    });
    p.addTask(Task("5", "0", "0", 3));
    EXPECT_EQ(4, p.numTaskPriority(3));
    EXPECT_EQ(2, p.numTaskPriority(0));
}

TEST(List, DefaultConstructor) {
    TodoList list;
    EXPECT_EQ("New List", list.getNameList());
    EXPECT_EQ(0, list.numTotTask());
}

TEST(List, TasksByDescription) {
    TodoList l("first", {
            Task("Drinking", "0", "0"),
            Task("Running", "0", "07:30"),
            Task("Work", "0", "08:30"),
            Task("Drinking", "0", "10:00"),
            Task("Cooking", "0", "13:00"),
            Task("Drinking", "0", "14:00"),
            Task("Work", "0", "14:30"),
            Task("Cooking", "0", "20:00"),
            Task("Drinking", "0", "20:30"),
            Task("Playing", "0", "21:00"),
    });
    l.setNameList("Daily");
    EXPECT_EQ("Daily", l.getNameList());
    TodoList p("Play", l.searchTask("Playing"));
    EXPECT_EQ(1, p.numTotTask());
    TodoList d("Drink", l.searchTask("Drinking"));
    EXPECT_EQ(4, d.numTotTask());
    TodoList c("Cook", l.searchTask("Cooking"));
    EXPECT_EQ(2, c.numTotTask());
    TodoList s("Swim", l.searchTask("Swimming"));
    EXPECT_EQ(0, s.numTotTask());
}
