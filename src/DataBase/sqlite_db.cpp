#include "DataBase/sqlite_db.h"

SQLiteDataBase::SQLiteDataBase(Widgets& widgets, tgui::Gui& dialog_gui, std::shared_ptr<Display>& dialog_ptr): m_widgets(widgets),m_dialog_gui(dialog_gui), m_dialog_ptr(dialog_ptr) {

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

	sqlite3_exec(database, request.c_str(), readDepartmentDataBase, this, nullptr); //READ DB DATA
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

		if (db_data.size()) { //<#######
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
		}	   //<#######
		else { //<#######
			m_widgets.output_list_view->removeAllItems(); //<#######
			std::string test = "SELECT name FROM PRAGMA_TABLE_INFO('" + m_table_name + "')";
			dataBaseRequest(m_db_name, m_table_name, test);

			for (int i = 0; i < test1.size(); ++i) {
				m_widgets.output_list_view->addColumn(test1[i]);
				m_widgets.output_list_view->setColumnAlignment(i, tgui::ListView::ColumnAlignment::Center);
			}
			test1.clear(); 
			return;
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

void SQLiteDataBase::deleteFromDataBase() {

	std::string request = "DELETE FROM " + m_table_name + " WHERE ";
	std::set<std::size_t>selected_item = m_widgets.output_list_view->getSelectedItemIndices();
	for (std::set<std::size_t>::iterator it = selected_item.begin(); it != selected_item.end(); ++it) {
		if ((*it) != -1) {
			for (int i = 0; i < m_widgets.output_list_view->getItemRow((*it)).size(); ++i) {

				std::string column = m_widgets.output_list_view->getColumnText(i).toStdString();
				std::string row = m_widgets.output_list_view->getItemRow((*it))[i].toStdString();

				request += column;
				request += " =";
				request += " '" + row + "' ";
				if (i == m_widgets.output_list_view->getItemRow((*it)).size() - 1) {
					break;
				}

				request += " AND ";
			}
		}
	}

	dataBaseRequest(m_db_name, m_table_name, request); 
	std::string redraw_output_window = "SELECT * FROM " + m_table_name;
	dataBaseRequest(m_db_name, m_table_name, redraw_output_window);
}

void SQLiteDataBase::insertIntoToDataBase() {

	std::string request = "INSERT INTO " + m_table_name + "(";

	for (int i = 0; i < m_widgets.output_list_view->getColumnCount(); ++i) {
		request += m_widgets.output_list_view->getColumnText(i).toStdString();
		if (i != m_widgets.output_list_view->getColumnCount() - 1) {
			request += ",";
		}
	}
	request += ") VALUES (";

	for (int i = 0; i < m_dialog_gui.getWidgets().size(); ++i) {
		if (m_dialog_gui.getWidgets()[i]->getWidgetType() == "EditBox") {
			auto ptr = dynamic_cast<tgui::EditBox*>(m_dialog_gui.getWidgets()[i].get());
			request += "'" + ptr->getText().toStdString() + "'";
			if (i != m_dialog_gui.getWidgets().size()) {
				request += ",";
			}
		}
	}
	request.pop_back();
	request += ")";
	dataBaseRequest(m_db_name, m_table_name, request);
	std::string redraw_output_window = "SELECT * FROM " + m_db_name;
	dataBaseRequest(m_db_name, m_table_name, redraw_output_window);
	m_dialog_ptr->getWindowPtr()->close();
	m_widgets.accept_button->setEnabled(false);
}


//SELECT name FROM PRAGMA_TABLE_INFO('salary');

int SQLiteDataBase::readDepartmentDataBase(void* notUsed, int argc, char** argv, char** columnName) {

	auto db_ptr = static_cast<SQLiteDataBase*>(notUsed);       
	db_ptr->m_widgets.output_list_view->removeAllItems();    
	db_ptr->m_widgets.output_list_view->removeAllColumns();   

	for (int i = 0; i < argc; ++i) { 
		std::string current_column = columnName[i];
		if (current_column == "name") {
			db_ptr->test1.emplace_back(argv[i]);
		}
		else {
			db_ptr->m_widgets.output_list_view->addColumn(columnName[i]);
			db_ptr->m_widgets.output_list_view->setColumnAlignment(i, tgui::ListView::ColumnAlignment::Center);
		}                                   																   
		db_ptr->db_data.emplace_back(argv[i]);                        
	}
	return 0;
}

