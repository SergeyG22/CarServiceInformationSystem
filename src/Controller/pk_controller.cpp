#include "Controller/pk_controller.h"

PkController::PkController(std::shared_ptr<SQLiteDataBase>& data_base, tgui::Gui& gui, tgui::Gui& dialog_gui, Widgets& widgets, std::shared_ptr<Display>& window_ptr , std::shared_ptr<Display>& dialog_ptr) : m_db_data(data_base), m_window_ptr(window_ptr), m_widgets(widgets), m_gui(gui) , m_dialog_gui(dialog_gui), m_dialog_ptr(dialog_ptr) {

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
		if (widgets.output_list_view->getColumnCount() != 0 && widgets.output_list_view->getItemCount() != 0) {
			m_dialog_ptr = std::make_unique<Window>(WINDOW_DIALOG_WIDTH, WINDOW_DIALOG_HEIGHT);
			m_dialog_ptr->getWindowPtr()->setTitle(L"Äîáàâèòü íîâóþ çàïèñü");
			m_dialog_gui.setTarget(*(m_dialog_ptr->getWindowPtr()));
			m_dialog_gui.removeAllWidgets();
	
			tgui::Theme m_theme{ "../themes/Black.txt" };

			tgui::EditBox::Ptr edit;
			int currentPositionEditBox = POS_Y_EDIT_BOX;
			for (int i = 0; i < widgets.output_list_view->getColumnCount(); ++i) {
				std::string str = widgets.output_list_view->getColumnText(i).toStdString();
				edit = tgui::EditBox::create();
				edit->setTextSize(TEXT_SIZE);
				edit->setSize(WIDTH_EDIT_BOX, HEIGHT_EDIT_BOX);
				edit->setRenderer(m_theme.getRenderer("EditBox"));
				edit->setPosition(POS_X_EDIT_BOX, currentPositionEditBox);
				edit->setDefaultText(str);
				m_dialog_gui.add(edit);
				currentPositionEditBox += INTERVAL_BETWEEN_EDIT_BOX;
			}
			m_widgets.accept_button->setPosition(POS_X_ACCEPT_BUTTON, currentPositionEditBox + 25);
			m_widgets.cancel_button->setPosition(POS_X_CANCEL_BUTTON, currentPositionEditBox + 25);
			m_dialog_ptr->getWindowPtr()->setSize(sf::Vector2u(WINDOW_DIALOG_WIDTH, currentPositionEditBox + 100));

			m_dialog_gui.add(m_widgets.accept_button);
		    m_dialog_gui.add(m_widgets.cancel_button);

		}
		
		});
	m_widgets.cancel_button->onPress([&] {
		m_dialog_ptr->getWindowPtr()->close();
		});

	m_widgets.remove_button->onPress([&] {
		std::cout << "Óäàëèòü\n";
		});
	m_widgets.edit_button->onPress([&] {
		std::cout << "Èçìåíèòü\n";
		});
	m_widgets.accept_button->onPress([&] {
		std::cout << "Ïðèìåíèòü\n";
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
		m_gui.handleEvent(event);				// ÊÎÃÄÀ ÇÀÊÊÎÌÅÍÒÈÐÓÅÌ ÐÀÁÎÒÀÅÒ ÌÀÑØÒÀÁÈÐÎÂÀÍÈÅ, ÍÎ ÍÅ ÐÀÁÎÒÀÞÒ ÊÍÎÏÊÈ!!!!
		mouseEvent(event, view_mouse_position);
		keyboardEvent(event);
	}
	
	sf::Event dialog_event;

	if (m_dialog_ptr != nullptr) {
		
		while (m_dialog_ptr->getWindowPtr()->pollEvent(dialog_event)) {

			if (dialog_event.type == sf::Event::Closed) {
				m_dialog_ptr->getWindowPtr()->close();
			}
			m_dialog_gui.handleEvent(dialog_event);
			mouseEvent(dialog_event, view_mouse_position);
			keyboardEvent(dialog_event);
		}
		
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
