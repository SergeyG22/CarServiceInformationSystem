#pragma once
#include "Controller/controller.h"
#include "View/display.h"
#include <iostream>

class PkController: public Controller{
	std::shared_ptr<Display> m_window_ptr;
public:
	PkController(std::shared_ptr<Display>& window_ptr);
	bool mouseEvent(const sf::Event&, const sf::Vector2f&);
	bool keyboardEvent(const sf::Event&);
	void eventLoop() override;
};