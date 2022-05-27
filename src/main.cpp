#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <winsqlite/winsqlite3.h>
#include <stdio.h>
#include "Facades/application.h"


//.open ../../databases/users.db  - переход к базе данных
//https://yandex.ru/video/preview/?filmId=8300103538392702947&p=1&text=sqlite3+%D1%83%D1%81%D1%82%D0%B0%D0%BD%D0%BE%D0%B2%D0%BA%D0%B0


//1)создать таблички через интерфейс DB
//2)заносить данные через приложение


static int callback(void* NotUsed, int argc, char** argv, char** azColName) {

    for (int i = 0; i < argc; ++i) {
        std::cout << azColName[i] <<':' << argv[i] <<'\n';
    }
    return 0;
}

int main() {

    //ПРИ КАЖДОМ ЗАПУСКЕ ОН СОЗДАЕТ НОВУЮ БАЗУ ДАННЫХ
    sqlite3* database;
    char** err = nullptr;
    int rc = sqlite3_open("../databases/users.db", &database);
    
    if (rc) {
       fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(database));
    }
    else {
       fprintf(stderr, "Opened database successfully\n");
    }
    std::cout << rc;

    /*
    std::string sql = "SELECT * from users";
    int result = sqlite3_exec(database, sql.c_str(), NULL, NULL, err);
    if (result != SQLITE_OK) {
        std::cout << "error\n";
    }

    sqlite3_exec(database, sql.c_str(), callback, NULL, NULL);
    */
    sqlite3_close(database);

    std::shared_ptr<Application>exec = std::make_unique<Application>();
    exec->applicationExec();

    return 0;
}