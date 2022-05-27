#include "Controller/pk_controller.h"

PkController::PkController(std::shared_ptr<Display>&window_ptr):m_window_ptr(window_ptr) {

}

void PkController::eventLoop() {
	sf::Event event;

	sf::Vector2i global_mouse_position = sf::Mouse::getPosition(*(m_window_ptr->getWindowPtr()));
	sf::Vector2f view_mouse_position = m_window_ptr->getWindowPtr()->mapPixelToCoords(global_mouse_position);

	while (m_window_ptr->getWindowPtr()->pollEvent(event)) {

		if (event.type == sf::Event::Closed) {
			m_window_ptr->getWindowPtr()->close();
		}
		mouseEvent(event, view_mouse_position);
		keyboardEvent(event);
	}

}

bool PkController::mouseEvent(const sf::Event& event, const sf::Vector2f& view_mouse_position) {
	if (event.type == sf::Event::MouseButtonPressed) {
		if (event.key.code == sf::Mouse::Left) {
			std::cout << "Mouse clicked\n";
		}
	}

	if (event.type == sf::Event::Resized) {
		std::cout << "resize\n";
		std::cout << m_window_ptr->getWindowPtr()->getSize().x << '\n';
		std::cout << m_window_ptr->getWindowPtr()->getSize().y << '\n';
	}


	return false;
}

bool PkController::keyboardEvent(const sf::Event& event) {

	if (event.type == sf::Event::KeyPressed) {
		switch (event.key.code) {

		case sf::Keyboard::Key::Space: {
			std::cout << "Keyboard space\n";
			break;
		}

		}
	}
	return false;
}
