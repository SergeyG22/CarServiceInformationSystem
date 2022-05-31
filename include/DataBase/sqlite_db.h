#pragma once
#include <vector>
#include <TGUI/TGUI.hpp>
#include "sqlite3.h"
#include "config.h"
#include "Graphics/widgets.h"

class SQLiteDataBase {
	Widgets& m_widgets;
	static int readDepartmentDataBase(void*, int, char**, char**);
	std::string m_db_name;
	std::string m_table_name;
public:
	SQLiteDataBase(Widgets&);
	std::vector<tgui::String>db_data;
	void dataBaseRequest(const std::string&, const std::string&, const std::string&);
	std::string getDataBaseName() const;
	std::string getTableName() const;
	void alignToWidth();
};
