#pragma once
#include "display.h"
#include "config.h"

class Window: public Display {
	unsigned int m_width;
	unsigned int m_height;
	sf::RenderWindow m_window {sf::VideoMode(m_width, m_height), L"�������������� ������� �������������� ������ ����������� �� ���"};
public:
	sf::RenderWindow* getWindowPtr() override;
	void render(tgui::Gui& ) override;
	bool getWindowState() const override;
	Window(const unsigned int, const unsigned int);
};