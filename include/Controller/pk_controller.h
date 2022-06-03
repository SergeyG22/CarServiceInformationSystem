#pragma once
#include "Controller/controller.h"
#include "View/display.h"
#include <iostream>
#include "Graphics/widgets.h"
#include "sqlite3.h"
#include "DataBase/sqlite_db.h"
#include "View/window.h"

class PkController: public Controller{
	std::shared_ptr<Display>& m_window_ptr;
	std::shared_ptr<Display>& m_dialog_ptr;
	std::shared_ptr<Widgets>& m_widgets;
	tgui::Gui& m_gui;
	tgui::Gui& m_dialog_gui;
	std::shared_ptr<SQLiteDataBase>& m_db_data;
public:
	PkController(std::shared_ptr<SQLiteDataBase>&, tgui::Gui&, tgui::Gui&, std::shared_ptr<Widgets>&, std::shared_ptr<Display>&, std::shared_ptr<Display>&);
	bool mouseEvent(const sf::Event&, const sf::Vector2f&);
	bool keyboardEvent(const sf::Event&);
	void eventLoop() override;
};