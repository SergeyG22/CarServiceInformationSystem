#include <gtest/gtest.h>
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <winsqlite/winsqlite3.h>
#include <stdio.h>
#include "View/display.h"


TEST(DataBaseTest, CheckingDataBaseApplication) {
    sqlite3* database_application;
    int db_application_is_open = sqlite3_open("../databases/applications.db", &database_application);
    ASSERT_EQ(0, db_application_is_open);
}

TEST(DataBaseTest, CheckingDataBaseComplexRepair) {
    sqlite3* database_complex_repair;
    int db_complex_repair_is_open = sqlite3_open("../databases/complex_repair.db", &database_complex_repair);
    ASSERT_EQ(0, db_complex_repair_is_open);
}

TEST(DataBaseTest, CheckingDataBaseCounterParties) {
    sqlite3* database_counter_parties;
    int db_counter_parties = sqlite3_open("../databases/counterparties.db", &database_counter_parties);
    ASSERT_EQ(0, db_counter_parties);
}

TEST(DataBaseTest, CheckingDataBaseDepartment) {
    sqlite3* database_department;
    int db_department = sqlite3_open("../databases/department.db", &database_department);
    ASSERT_EQ(0, db_department);
}

TEST(DataBaseTest, CheckindDataBaseNodeRepair) {
    sqlite3* database_node_repair;
    int db_node_repair = sqlite3_open("../databases/repair_of_nodes.db", &database_node_repair);
    ASSERT_EQ(0, db_node_repair);
}

TEST(DataBaseTest, CheckingDataBaseSimpleRepair) {
    sqlite3* database_simple_repair;
    int db_simple_repair = sqlite3_open("../databases/simple_repair.db", &database_simple_repair);
    ASSERT_EQ(0, db_simple_repair);
}

TEST(DataBaseTest, CheckingDataBaseEmployees) {
    sqlite3* database_employees;
    int db_employees = sqlite3_open("../databases/employees.db", &database_employees);
    ASSERT_EQ(0, db_employees);
}

//???????? ????, ??? ??????? ??? ???????