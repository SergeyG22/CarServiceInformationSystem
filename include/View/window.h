#pragma once
#include "display.h"
#include "config.h"

class Window: public Display {
	unsigned int m_width;
	unsigned int m_height;
	sf::Clock clock;
	sf::RenderWindow m_window {sf::VideoMode(m_width, m_height), L"Информационная система интерактивного приема автомобилей на СТО"};
public:
	sf::RenderWindow* getWindowPtr() override;
	void render(tgui::Gui&, std::vector<std::unique_ptr<RenderingElement>>&) override;
	bool getWindowState() const override;
	Window(const unsigned int, const unsigned int);
};