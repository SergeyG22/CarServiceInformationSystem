#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <winsqlite/winsqlite3.h>
#include <stdio.h>
#include "Facades/application.h"


//.open ../../databases/users.db  - переход к базе данных
//https://yandex.ru/video/preview/?filmId=8300103538392702947&p=1&text=sqlite3+%D1%83%D1%81%D1%82%D0%B0%D0%BD%D0%BE%D0%B2%D0%BA%D0%B0


int main() {
    setlocale(LC_ALL, "russian");
    std::shared_ptr<Application>exec = std::make_unique<Application>();
    exec->applicationExec();
    return 0;
}