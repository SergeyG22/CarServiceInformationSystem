#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <winsqlite/winsqlite3.h>
#include <stdio.h>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    tgui::Label::Ptr topLabel;
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sqlite3* db;
    sqlite3_open("example.db", &db);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}