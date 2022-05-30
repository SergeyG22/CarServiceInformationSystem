#pragma once
#include <vector>
#include <TGUI/TGUI.hpp>
#include "sqlite3.h"
#include "config.h"
#include "Graphics/widgets.h"

class SQLiteDataBase {
	Widgets& m_widgets;
	static int readDepartmentDataBase(void*, int, char**, char**);
public:
	SQLiteDataBase(Widgets&);
	std::vector<tgui::String>db_data;
	void dataBaseRequest(const std::string&, const std::string&);
};
