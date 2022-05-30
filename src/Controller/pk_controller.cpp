#include "Controller/pk_controller.h"

PkController::PkController(std::shared_ptr<SQLiteDataBase>& data_base, tgui::Gui& gui, Widgets& widgets, std::shared_ptr<Display>& window_ptr): m_db_data(data_base), m_window_ptr(window_ptr), m_widgets(widgets), m_gui(gui) {

	m_widgets.departments_view_button->onPress([&] {
		data_base->dataBaseRequest("department", "department");
		});
	m_widgets.counterparties_view_button->onPress([&] {
		data_base->dataBaseRequest("counterparties", "counterparties");
		});
	m_widgets.employees_view_button->onPress([&] {
		data_base->dataBaseRequest("employees", "employees");
		});
	m_widgets.applications_view_button->onPress([&] {
		data_base->dataBaseRequest("applications", "applications");
		});
	m_widgets.repair_of_nodes_view_button->onPress([&] {
		data_base->dataBaseRequest("repair_of_nodes", "repair_of_nodes");
		});
	m_widgets.simple_repair_view_button->onPress([&] {
		data_base->dataBaseRequest("simple_repair", "simple_repair");
		});
	m_widgets.complex_repairs_view_button->onPress([&] {
		data_base->dataBaseRequest("complex_repair", "complex_repair");
		});
	m_widgets.earnings_of_employees_view_button->onPress([&] {
		data_base->dataBaseRequest("salary","salary");
		});
	m_widgets.add_button->onPress([&] {
		std::cout << "Äîáàâèòü\n";
		});
	m_widgets.remove_button->onPress([&] {
		std::cout << "Óäàëèòü\n";
		});
	m_widgets.edit_button->onPress([&] {
		std::cout << "Èçìåíèòü\n";
		});
	m_widgets.accept_button->onPress([&] {
		std::cout << "Ïğèìåíèòü\n";
		});
	m_widgets.exit_button->onPress([&] {
		std::cout << "Âûéòè\n";
		});
}

void PkController::eventLoop() {
	sf::Event event;

	sf::Vector2i global_mouse_position = sf::Mouse::getPosition(*(m_window_ptr->getWindowPtr()));
	sf::Vector2f view_mouse_position = m_window_ptr->getWindowPtr()->mapPixelToCoords(global_mouse_position);

	while (m_window_ptr->getWindowPtr()->pollEvent(event)) {

		if (event.type == sf::Event::Closed) {
			m_window_ptr->getWindowPtr()->close();
		}
		m_gui.handleEvent(event);				// ÊÎÃÄÀ ÇÀÊÊÎÌÅÍÒÈĞÓÅÌ ĞÀÁÎÒÀÅÒ ÌÀÑØÒÀÁÈĞÎÂÀÍÈÅ, ÍÎ ÍÅ ĞÀÁÎÒÀŞÒ ÊÍÎÏÊÈ!!!!
		mouseEvent(event, view_mouse_position);
		keyboardEvent(event);
	}

}

bool PkController::mouseEvent(const sf::Event& event, const sf::Vector2f& view_mouse_position) {
	if (event.type == sf::Event::MouseButtonPressed) {
		if (event.key.code == sf::Mouse::Left) {

		}
	}

	return false;
}

bool PkController::keyboardEvent(const sf::Event& event) {

	if (event.type == sf::Event::KeyPressed) {
		switch (event.key.code) {

		case sf::Keyboard::Key::Space: {

			break;
		}

		}
	}
	return false;
}
