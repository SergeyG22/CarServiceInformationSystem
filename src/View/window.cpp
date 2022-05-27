#include "View/window.h"

sf::RenderWindow* Window::getWindowPtr() {
	return &m_window;
}

void Window::render() {
	m_window.clear();

	//window draw is here

	m_window.display();
}

bool Window::isOpen() const {
	return m_window.isOpen();
}