#pragma once
#include "View/window.h"
#include "Controller/pk_controller.h"
#include "Graphics/widgets.h"
#include "TGUI/TGUI.hpp"
#include "DataBase/sqlite_db.h"

class Application{
	std::shared_ptr<Display> m_display_ptr = std::make_unique<Window>();
	tgui::Gui m_gui { *(m_display_ptr->getWindowPtr()) };
	std::shared_ptr<Controller> m_controller_ptr;
	std::shared_ptr<SQLiteDataBase> m_database;
	Widgets m_widgets;
public:
	Application();
	void applicationExec();
};