#include "View/window.h"

sf::RenderWindow* Window::getWindowPtr() {
	return &m_window;
}

void Window::render(tgui::Gui& gui, std::vector<std::unique_ptr<RenderingElement>>& elements) {
	
	m_window.clear(sf::Color::White);
	gui.draw();
	//window draw is here
	for (int i = 0; i < elements.size(); ++i) {
		m_window.draw(elements[i]->sprite);
	}

	m_window.display();
	
	sf::Int32 frame_duration = clock.getElapsedTime().asMilliseconds();
	sf::Int32 time_to_sleep = int(VALUE_OF_SCREEN_RATE / FPS) - frame_duration;
	if (time_to_sleep > 0) {
		sf::sleep(sf::milliseconds(time_to_sleep));
	}
	clock.restart();
	
}

bool Window::getWindowState() const {
	return m_window.isOpen();
}


Window::Window(const unsigned int width, const unsigned int height): m_width(width), m_height(height) {

}


