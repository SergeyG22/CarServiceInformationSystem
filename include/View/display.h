#pragma once
#include <SFML/Graphics.hpp>

class Display{
	
public:
	virtual ~Display() = default;
	virtual sf::RenderWindow* getWindowPtr() = 0;
	virtual bool isOpen() const = 0;
	virtual void render() = 0;
};