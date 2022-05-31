#include "DataBase/sqlite_db.h"

SQLiteDataBase::SQLiteDataBase(Widgets& widgets): m_widgets(widgets) {

}

void SQLiteDataBase::dataBaseRequest(const std::string& db_name, const std::string& table_name, const std::string& request) { 
	db_data.clear();
	sqlite3* database;
	char** error = nullptr;
	m_db_name = db_name;
	m_table_name = table_name;

	std::string db_path = "../databases/" + getDataBaseName() + ".db";
	int connection = sqlite3_open(db_path.c_str(), &database);

	if (connection) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(database));
	}
	else {
	//	fprintf(stderr, "Opened database successfully!\n");
	}
	
	int result = sqlite3_exec(database, request.c_str(), nullptr, nullptr, error);
	if (result != SQLITE_OK) {
		std::cout << "invalid request\n";
	}

	sqlite3_exec(database, request.c_str(), readDepartmentDataBase, this, nullptr);
	alignToWidth();
	sqlite3_close(database);
}

std::string SQLiteDataBase::getDataBaseName() const {
	return m_db_name;
}

std::string SQLiteDataBase::getTableName() const {
	return m_table_name;
}

void SQLiteDataBase::alignToWidth() {
	int current_number_of_columns = m_widgets.output_list_view->getColumnCount();
	int maximum_column_string_lenght = 0;

	for (int i = 0; i < current_number_of_columns; ++i) {
		m_widgets.output_list_view->getColumnText(i).size();
		if (maximum_column_string_lenght < m_widgets.output_list_view->getColumnText(i).size()) {
			maximum_column_string_lenght = m_widgets.output_list_view->getColumnText(i).size();
		}
	}

	int column_counter = 0;
	int maximum_string_length = 0;
	std::vector<tgui::String>cell_data;
	for (auto data : db_data) {
		cell_data.emplace_back(data);
		column_counter++;
		if (maximum_string_length < data.size()) {
			maximum_string_length = data.size();
		}
		if (column_counter == current_number_of_columns) {
			m_widgets.output_list_view->addItem(cell_data);
			column_counter = 0;
			cell_data.clear();
		}
	}

	for (int i = 0; i < m_widgets.output_list_view->getColumnCount(); ++i) {

		if (maximum_string_length > maximum_column_string_lenght) {
			m_widgets.output_list_view->setColumnWidth(i, STRING_MULTIPLIER * maximum_string_length);
		}
		else {
			m_widgets.output_list_view->setColumnWidth(i, STRING_MULTIPLIER * maximum_column_string_lenght);
		}
	}
}

int SQLiteDataBase::readDepartmentDataBase(void* notUsed, int argc, char** argv, char** columnName) {

	auto db_ptr = static_cast<SQLiteDataBase*>(notUsed);
	db_ptr->m_widgets.output_list_view->removeAllItems();
	db_ptr->m_widgets.output_list_view->removeAllColumns();
	for (int i = 0; i < argc; ++i) {
		db_ptr->m_widgets.output_list_view->addColumn(columnName[i]);
		db_ptr->db_data.emplace_back(argv[i]);
		db_ptr->m_widgets.output_list_view->setColumnAlignment(i, tgui::ListView::ColumnAlignment::Center);
	}
	return 0;
}

