#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <winsqlite/winsqlite3.h>
#include <stdio.h>
#include "Facades/application.h"


int main() {
    setlocale(LC_ALL, "russian");
    std::shared_ptr<Application>exec = std::make_unique<Application>();
    exec->applicationExec();
    return 0;
}