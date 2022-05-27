#pragma once
#include "View/window.h"
#include "Controller/pk_controller.h"

class Application{
	std::shared_ptr<Display> m_display_ptr;
	std::shared_ptr<Controller> m_controller_ptr;
	//тут кнопки
public:
	Application();
	void applicationExec();
};