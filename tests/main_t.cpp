#include <gtest/gtest.h>
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <winsqlite/winsqlite3.h>
#include <stdio.h>

TEST(HelloTest, BasicAssertions) {
  sqlite3* db;
  sqlite3_open("example.db", &db);
  tgui::Label::Ptr topLabel;
  EXPECT_EQ(7 * 6, 42);
}