#include "Graphics/widgets.h"

Widgets::Widgets() {
	departments_view_button = tgui::Button::create();
	departments_view_button->setText(L"�����������");
	departments_view_button->setSize(BUTTON_WIDTH, BUTTON_HEIGHT);
	departments_view_button->setPosition(POS_X_DEPARTMENTS_VIEW_BUTTON, POS_Y_DEPARTMENTS_VIEW_BUTTON);
	departments_view_button->setTextSize(TEXT_SIZE);
	counterparties_view_button = tgui::Button::create();
	counterparties_view_button->setText(L"�����������");
	counterparties_view_button->setPosition(POS_X_COUNTERPARTIES_VIEW_BUTTON, POS_Y_COUNTERPARTIES_VIEW_BUTTON);
	counterparties_view_button->setSize(BUTTON_WIDTH, BUTTON_HEIGHT);
	counterparties_view_button->setTextSize(TEXT_SIZE);
	employees_view_button = tgui::Button::create();
	employees_view_button->setText(L"����������");
	employees_view_button->setPosition(POS_X_EMPLOYEES_VIEW_BUTTON, POS_Y_EMPLOYEES_VIEW_BUTTON);
	employees_view_button->setSize(BUTTON_WIDTH, BUTTON_HEIGHT);
	employees_view_button->setTextSize(TEXT_SIZE);
	applications_view_button = tgui::Button::create();
	applications_view_button->setText(L"������");
	applications_view_button->setPosition(POS_X_APPLICATIONS_VIEW_BUTTON, POS_Y_APPLICATIONS_VIEW_BUTTON);
	applications_view_button->setSize(BUTTON_WIDTH, BUTTON_HEIGHT);
	applications_view_button->setTextSize(TEXT_SIZE);
	repair_of_nodes_view_button = tgui::Button::create();
	repair_of_nodes_view_button->setText(L"������ �����");
	repair_of_nodes_view_button->setPosition(POS_X_REPAIR_OF_NODES_VIEW_BUTTON, POS_Y_REPAIR_OF_NODES_VIEW_BUTTON);
	repair_of_nodes_view_button->setSize(BUTTON_WIDTH, BUTTON_HEIGHT);
	repair_of_nodes_view_button->setTextSize(TEXT_SIZE);
	simple_repair_view_button = tgui::Button::create();
	simple_repair_view_button->setText(L"������� ������");
	simple_repair_view_button->setPosition(POS_X_SIMPLE_REPAIR_VIEW_BUTTON, POS_Y_SIMPLE_REPAIR_VIEW_BUTTON);
	simple_repair_view_button->setSize(BUTTON_WIDTH, BUTTON_HEIGHT);
	simple_repair_view_button->setTextSize(TEXT_SIZE);
	complex_repairs_view_button = tgui::Button::create();
	complex_repairs_view_button->setText(L"������� ������");
	complex_repairs_view_button->setPosition(POS_X_COMPLEX_REPAIR_VIEW_BUTTON, POS_Y_COMPLEX_REPAIR_VIEW_BUTTON);
	complex_repairs_view_button->setSize(BUTTON_WIDTH, BUTTON_HEIGHT);
	complex_repairs_view_button->setTextSize(TEXT_SIZE);
	earnings_of_employees_view_button = tgui::Button::create();
	earnings_of_employees_view_button->setText(L"��������� �����������");
	earnings_of_employees_view_button->setPosition(POS_X_EARNINGS_OF_EMPLOYEES_VIEW_BUTTON, POS_Y_EARNINGS_OF_EMPLOYEES_VIEW_BUTTON);
	earnings_of_employees_view_button->setSize(BUTTON_WIDTH, BUTTON_HEIGHT);
	earnings_of_employees_view_button->setTextSize(TEXT_SIZE);
	accept_button = tgui::Button::create();
	accept_button->setText(L"���������");
	accept_button->setPosition(POS_X_ACCEPT_BUTTON, POS_Y_ACCEPT_BUTTON);
	accept_button->setSize(BUTTON_WIDTH_BOTTOM_PANEL, BUTTON_HEIGHT_BOTTOM_PANEL);
	accept_button->setTextSize(TEXT_SIZE);
	edit_button = tgui::Button::create();
	edit_button->setText(L"��������");
	edit_button->setPosition(POS_X_EDIT_BUTTON, POS_Y_EDIT_BUTTON);
	edit_button->setSize(BUTTON_WIDTH_BOTTOM_PANEL, BUTTON_HEIGHT_BOTTOM_PANEL);
	edit_button->setTextSize(TEXT_SIZE);
	exit_button = tgui::Button::create();
	exit_button->setText(L"�����");
	exit_button->setPosition(POS_X_EXIT_BUTTON, POS_Y_EXIT_BUTTON);
	exit_button->setSize(BUTTON_WIDTH_BOTTOM_PANEL, BUTTON_HEIGHT_BOTTOM_PANEL);
	exit_button->setTextSize(TEXT_SIZE);
	add_button = tgui::Button::create();
	add_button->setText(L"��������");
	add_button->setPosition(POS_X_ADD_BUTTON, POS_Y_ADD_BUTTON);
	add_button->setSize(BUTTON_WIDTH_BOTTOM_PANEL, BUTTON_HEIGHT_BOTTOM_PANEL);
	add_button->setTextSize(TEXT_SIZE);
	remove_button = tgui::Button::create();
	remove_button->setText(L"�������");
	remove_button->setPosition(POS_X_REMOVE_BUTTON, POS_Y_REMOVE_BUTTON);
	remove_button->setSize(BUTTON_WIDTH_BOTTOM_PANEL, BUTTON_HEIGHT_BOTTOM_PANEL);
	remove_button->setTextSize(TEXT_SIZE);
	output_list_view = tgui::ListView::create();
	output_list_view->setPosition(POS_X_OUTPUT_WINDOW, POS_Y_OUTPUT_WINDOW);
	output_list_view->setSize(OUTPUT_WINDOW_WIDTH, OUTPUT_WINDOW_HEIGHT);

	departments_view_button->setRenderer(m_theme.getRenderer("Button"));
	counterparties_view_button->setRenderer(m_theme.getRenderer("Button"));
	employees_view_button->setRenderer(m_theme.getRenderer("Button"));
	applications_view_button->setRenderer(m_theme.getRenderer("Button"));
	repair_of_nodes_view_button->setRenderer(m_theme.getRenderer("Button"));
	simple_repair_view_button->setRenderer(m_theme.getRenderer("Button"));
	complex_repairs_view_button->setRenderer(m_theme.getRenderer("Button"));
	earnings_of_employees_view_button->setRenderer(m_theme.getRenderer("Button"));

	accept_button->setRenderer(m_theme.getRenderer("Button"));
	edit_button->setRenderer(m_theme.getRenderer("Button"));
	exit_button->setRenderer(m_theme.getRenderer("Button"));
	remove_button->setRenderer(m_theme.getRenderer("Button"));
	add_button->setRenderer(m_theme.getRenderer("Button"));

	output_list_view->setRenderer(m_theme.getRenderer("ListView"));
	output_list_view->setTextSize(25);
	/*
	output_list_view->addColumn("Column1");
	output_list_view->addColumn("Column2");
	output_list_view->addColumn("Column3");
	output_list_view->setColumnAlignment(0, tgui::ListView::ColumnAlignment::Center);
	output_list_view->setColumnAlignment(1, tgui::ListView::ColumnAlignment::Center);
	output_list_view->setColumnAlignment(2, tgui::ListView::ColumnAlignment::Center);
	std::vector<tgui::String>vec = {"1111111111111","HELOOOOO","3"};
	std::vector<tgui::String>vec2 = { "1","2","3" };
	output_list_view->addItem(vec);
	output_list_view->addItem(vec2);
	std::cout << output_list_view->getItemCount();
	
	output_list_view->setAutoScroll(true);
	*/
}


