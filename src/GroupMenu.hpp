<<<<<<< HEAD
#ifndef TASKBAR_BUTTON_MENU_HPP
#define TASKBAR_BUTTON_MENU_HPP
=======
/*
 * Taskbar Taskbar - A modern, minimalist taskbar for XFCE
 * Copyright (c) 2019-2020 Nicolas Szabo <nszabo@vivaldi.net>
 * gnu.org/licenses/gpl-3.0
 */

#ifndef DOCK_BUTTON_MENU_HPP
#define DOCK_BUTTON_MENU_HPP
>>>>>>> mirai-patch/master

#include <gtk/gtk.h>

#include <iostream>

class Group;
class GroupMenuItem;

class GroupMenu
{
<<<<<<< HEAD
	public:
		GroupMenu(Group* taskbarButton);
=======
  public:
	GroupMenu(Group* dockButton);

	void add(GroupMenuItem* menuItem);
	void remove(GroupMenuItem* menuItem);
>>>>>>> mirai-patch/master

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