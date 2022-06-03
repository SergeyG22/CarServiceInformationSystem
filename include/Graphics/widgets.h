#pragma once
#include "TGUI/TGUI.hpp"
#include "config.h"

class Widgets{
	tgui::Theme m_theme { "../themes/Black.txt" };
public:
	tgui::Button::Ptr departments_view_button;
	tgui::Button::Ptr counterparties_view_button;
	tgui::Button::Ptr employees_view_button;
	tgui::Button::Ptr applications_view_button;
	tgui::Button::Ptr repair_of_nodes_view_button;
	tgui::Button::Ptr simple_repair_view_button;
	tgui::Button::Ptr complex_repairs_view_button;
	tgui::Button::Ptr earnings_of_employees_view_button;
	tgui::Button::Ptr accept_button;
	tgui::Button::Ptr cancel_button;
	tgui::Button::Ptr change_button;
	tgui::Button::Ptr edit_button;
	tgui::Button::Ptr exit_button;
	tgui::Button::Ptr add_button;
	tgui::Button::Ptr remove_button;
	tgui::ListView::Ptr output_list_view;
	Widgets();
};