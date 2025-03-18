#include "gtest/gtest.h"

#include "../Task.h"

TEST(Task, DefaultConstructor) {
    Task t;
    EXPECT_EQ("Activity", t.getDescription());
    // EXPECT_STRCASEEQ("actIVITY", "AcTiViTry");   // trying C-strings comparison
    EXPECT_EQ("today", t.getDate());
    EXPECT_EQ("10:00 AM", t.getTime());
    EXPECT_EQ(0, t.getPriority()) << "Default Task has priority != 0";
    EXPECT_FALSE(t.isDone()) << "Default Task should NOT be DONE";
}
