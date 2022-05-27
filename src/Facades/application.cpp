#include "Facades/application.h"

Application::Application() {
	m_controller_ptr = std::make_unique<PkController>(m_display_ptr);
	m_gui.add(m_widgets.departments_view_button);
	m_gui.add(m_widgets.counterparties_view_button);
	m_gui.add(m_widgets.employees_view_button);
	m_gui.add(m_widgets.applications_view_button);
	m_gui.add(m_widgets.repair_of_nodes_view_button);
	m_gui.add(m_widgets.simple_repair_view_button);
	m_gui.add(m_widgets.complex_repairs_view_button);
	m_gui.add(m_widgets.earnings_of_employees_view_button);
	m_gui.add(m_widgets.accept_button);
	m_gui.add(m_widgets.edit_button);
	m_gui.add(m_widgets.exit_button);
	m_gui.add(m_widgets.output_list_view);
	m_gui.add(m_widgets.add_button);
	m_gui.add(m_widgets.remove_button);
}

void Application::applicationExec() {
	while (m_display_ptr->isOpen()) {
		m_display_ptr->render(m_gui);
		m_controller_ptr->eventLoop();
	}
}