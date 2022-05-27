#pragma once
#include "display.h"
#include "config.h"

class Window: public Display {
	sf::RenderWindow m_window {sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "CarServiceInformationSystem"};
public:
	sf::RenderWindow* getWindowPtr() override;
	void render() override;
	bool isOpen() const override;
};