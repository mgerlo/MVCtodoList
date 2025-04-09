#include "gtest/gtest.h"

#include "../Task.h"

TEST(Task, DefaultConstructor) {
    Task t;
    EXPECT_EQ("Activity", t.getDescription());
    // EXPECT_STRCASEEQ("actIVITY", "AcTiViTry");   // trying C-strings comparison
    EXPECT_EQ("01-01-2025", t.getDate());
    EXPECT_EQ("10:00", t.getTime());
    EXPECT_EQ(0, t.getPriority()) << "Default Task has priority != 0";
    EXPECT_FALSE(t.isDone()) << "Default Task should NOT be DONE";
}

// Test formati validi data e orario
TEST(Task, ValidConstructor) {
    EXPECT_NO_THROW(Task("Prova", "01-01-2020", "16:00"));
}

// Test formato data non valido
TEST(Task, InvalidDate) {
    EXPECT_THROW(Task("Errore data", "2025-01-01"), invalid_argument);
}

// Test formato orario non valido
TEST(Task, InvalidTime) {
    EXPECT_THROW(Task("Errore orario", "01-01-2025", "Paperino", 1, false), invalid_argument);
}
