#include "gtest/gtest.h"

#include "../Task.h"

TEST(Task, DefaultConstructor) {
    Task t;
    EXPECT_EQ("Activity", t.getDescription());
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
    EXPECT_THROW(Task("Errore data", "2025-01-01"), invalid_argument);
    EXPECT_THROW(Task("Partita", "01/01/2025"), invalid_argument);
    EXPECT_THROW(Task("Invalid", "N"), invalid_argument);
}

TEST(Task, InvalidRangeDate) {
    EXPECT_THROW(Task("Errore data", "32-00-2025"), invalid_argument);
}

// Test formato orario non valido
TEST(Task, InvalidTime) {
    EXPECT_THROW(Task("Errore orario", "01-01-2025", "Paperino", 1, false), invalid_argument);
    EXPECT_THROW(Task("Invalid", "0", "null"), invalid_argument);
}

TEST(Task, InvalidRangeTime) {
    EXPECT_THROW(Task("Errore orario", "01-01-2025", "24:85", 1, false), invalid_argument);
}

// Test data CALENDARIO GREGORIANO, anno bisestile...
TEST(Task, GregorianCalendar) {
    EXPECT_THROW(Task("Data1", "31-06-2024"), invalid_argument);
    EXPECT_NO_THROW(Task("Data2", "29-02-2020"));
    EXPECT_NO_THROW(Task("Data3", "29-02-2024"));
    EXPECT_THROW(Task("Data4", "29-02-2025"), invalid_argument);
    EXPECT_THROW(Task("Data5", "31-04-2020"), invalid_argument);
    EXPECT_NO_THROW(Task("Data6", "29-02-2000"));
}
