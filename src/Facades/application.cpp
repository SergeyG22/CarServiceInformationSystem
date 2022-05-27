#include "Facades/application.h"

Application::Application() {
	m_display_ptr = std::make_unique<Window>();
	m_controller_ptr = std::make_unique<PkController>(m_display_ptr);
}

void Application::applicationExec() {
	while (m_display_ptr->isOpen()) {
		m_display_ptr->render();
		m_controller_ptr->eventLoop();
	}
}