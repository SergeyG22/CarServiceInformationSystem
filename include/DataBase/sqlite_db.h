#pragma once
#include <vector>
#include <TGUI/TGUI.hpp>
#include "sqlite3.h"
#include "config.h"
#include "Graphics/widgets.h"
#include "View/window.h"

class SQLiteDataBase {
	Widgets& m_widgets;
	static int readDepartmentDataBase(void*, int, char**, char**);
	std::string m_db_name;
	std::string m_table_name;
	tgui::Gui& m_dialog_gui;
	std::shared_ptr<Display>& m_dialog_ptr;
	std::vector<tgui::String>test1;
public:
	SQLiteDataBase(Widgets&, tgui::Gui&, std::shared_ptr<Display>&);
	std::vector<tgui::String>db_data;
	void dataBaseRequest(const std::string&, const std::string&, const std::string&);
	std::string getDataBaseName() const;
	std::string getTableName() const;
	void alignToWidth();
	void deleteFromDataBase();
	void insertIntoToDataBase();
};
