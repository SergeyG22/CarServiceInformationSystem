#pragma once
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>

class Display{
	
public:
	virtual ~Display() = default;
	virtual sf::RenderWindow* getWindowPtr() = 0;
	virtual bool getWindowState() const = 0;
	virtual void render(tgui::Gui&) = 0;
protected:

};