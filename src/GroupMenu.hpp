#ifndef TASKBAR_BUTTON_MENU_HPP
#define TASKBAR_BUTTON_MENU_HPP

#include <iostream>

#include <gtk/gtk.h>


class Group;
class GroupMenuItem;

class GroupMenu
{
	public:
		GroupMenu(Group* taskbarButton);

		void add(GroupMenuItem& menuItem);
		void remove(GroupMenuItem& menuItem);

		void popup();
		void hide();

		uint getPointerDistance();

		Group* mGroup;
		
		GtkWidget* mWindow;
		GtkWidget* mBox;

		bool mVisible;
		bool mMouseHover;
};

#endif 