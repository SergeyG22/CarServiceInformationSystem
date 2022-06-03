#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class RenderingElement{
	std::string m_file_name;
	sf::Texture m_texture;
public:
	RenderingElement(const std::string&, const float&, const float&);
	sf::Sprite sprite;
	std::string getFileName() const;
};