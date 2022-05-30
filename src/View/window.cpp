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

bool Window::getWindowState() const {
	return m_window.isOpen();
}


Window::Window(const unsigned int width, const unsigned int height): m_width(width), m_height(height) {

}


// getWindowState
//setWindowState(Open Close)
//установить окну статус открыто оно или нет 
