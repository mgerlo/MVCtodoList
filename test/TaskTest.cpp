#include "gtest/gtest.h"

#include "../Task.h"

TEST(Task, Constructor) {
    Task t("1", "0", "0");
    EXPECT_EQ("1", t.getDescription());
    // EXPECT_STRCASEEQ("actIVITY", "AcTiViTry");   // trying C-strings comparison
    EXPECT_EQ("0", t.getDate());
    EXPECT_EQ("0", t.getTime());
    EXPECT_EQ(0, t.getPriority()) << "Default Task has priority != 0";
    EXPECT_FALSE(t.isDone()) << "Default Task should NOT be DONE";
}

// Test formati validi data e orario
TEST(Task, ValidConstructor) {
    EXPECT_NO_THROW(Task("Prova", "01-01-2020", "16:00"));
    EXPECT_NO_THROW(Task("0", "0", "0"));
}

// Test formato data non valido
TEST(Task, InvalidDate) {
    EXPECT_THROW(Task("Errore data", "2025-01-01", "0"), invalid_argument);
    EXPECT_THROW(Task("Invalid", "N", "0"), invalid_argument);
}

TEST(Task, InvalidRangeDate) {
    EXPECT_THROW(Task("Errore data", "32-00-2025", "0"), invalid_argument);
}

// Test formato orario non valido
TEST(Task, InvalidTime) {
    EXPECT_THROW(Task("Errore orario", "01-01-2025", "Paperino", 1, false), invalid_argument);
    EXPECT_THROW(Task("Invalid", "0", "null"), invalid_argument);
}

TEST(Task, InvalidRangeTime) {
    EXPECT_THROW(Task("Errore orario", "01-01-2025", "24:85", 1, false), invalid_argument);
}
