#include "Graphics/rendering_element.h"

RenderingElement::RenderingElement(const std::string& file_name, const float& pos_x, const float& pos_y) {
	if (!m_texture.loadFromFile("../resources/images/" + file_name)) {
		std::cerr << "error loading the " << file_name << " file";
	}
	m_file_name = file_name;
	sprite.setTexture(m_texture);
	sprite.setPosition(pos_x, pos_y);
}

std::string RenderingElement::getFileName() const {
	return m_file_name;
}