#pragma once
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <Graphics/rendering_element.h>

class Display{
	
public:
	virtual ~Display() = default;
	virtual sf::RenderWindow* getWindowPtr() = 0;
	virtual bool getWindowState() const = 0;
	virtual void render(tgui::Gui&, std::vector<std::unique_ptr<RenderingElement>>&) = 0;
protected:

};