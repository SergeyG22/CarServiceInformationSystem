#include "View/window.h"

sf::RenderWindow* Window::getWindowPtr() {
	return &m_window;
}

void Window::render(tgui::Gui& gui) {
	m_window.clear(sf::Color::Red);
	gui.draw();
	//window draw is here

	m_window.display();
}

bool Window::isOpen() const {
	return m_window.isOpen();
}