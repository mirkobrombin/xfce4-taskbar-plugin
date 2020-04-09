#ifndef TASKBAR_BUTTON_MENU_ITEM_HPP
#define TASKBAR_BUTTON_MENU_ITEM_HPP

#include <iostream>

#include <gtk/gtk.h>

#include "Helpers.hpp"

class GroupWindow;

class GroupMenuItem
{
	public:
		GroupMenuItem(GroupWindow* groupWindow);

		void updateLabel();
		void updateIcon();

		GroupWindow* mGroupWindow;
		
		GtkEventBox* mItem;
		GtkGrid* mGrid;
		GtkImage* mIcon;
		GtkLabel* mLabel;
		GtkButton* mCloseButton;

		Help::Gtk::Timeout mDragSwitchTimeout;
};

#endif 