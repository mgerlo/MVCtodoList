#include "gtest/gtest.h"

#include "../Task.h"

class TaskSuite : public ::testing::Test {
protected:
    Task t;

    void SetUp() override {
        t.setDescription("Back to the Future");
        t.setDate("tomorrow");
        t.setTime("22:04");
        t.setPriority(3);
        t.setDone(true);
    }
};

TEST_F(TaskSuite, TestConstructor) {
    EXPECT_EQ("Back to the Future", t.getDescription()) << "Wrong description setter method";
    EXPECT_EQ("tomorrow", t.getDate()) << "Wrong date setter method";
    EXPECT_EQ("22:04", t.getTime()) << "Wrong time setter method";
    EXPECT_EQ(3, t.getPriority()) << "Wrong priority setter method";
    EXPECT_TRUE(t.isDone()) << "Wrong done setter method";
}
