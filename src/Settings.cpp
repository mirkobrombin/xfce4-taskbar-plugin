/*
 * Taskbar Taskbar - A modern, minimalist taskbar for XFCE
 * Copyright (c) 2019-2020 Nicolas Szabo <nszabo@vivaldi.net>
 * gnu.org/licenses/gpl-3.0
 */

#include "Settings.hpp"

namespace Settings
{
	std::string mPath;
	GKeyFile* mFile;

	State<bool> forceIconSize;
	State<int> iconSize;

	State<bool> showWindowsListIfSingle;
	State<bool> onlyDisplayVisible;
	State<bool> onlyDisplayScreen;

	State<int> indicatorOrientation;
	State<int> indicatorStyle;
	State<GdkRGBA*> indicatorColor;

	State<bool> keyComboActive;
	State<bool> keyAloneActive;

	State<std::list<std::string>> pinnedAppList;

	void init()
	{

		mPath = xfce_panel_plugin_save_location(Plugin::mXfPlugin, true);

		mFile = g_key_file_new();
		g_key_file_load_from_file(mFile, mPath.c_str(), G_KEY_FILE_NONE, NULL);

		indicatorOrientation.setup(g_key_file_get_integer(mFile, "user", "indicatorOrientation", NULL),
			[](int indicatorOrientation) -> void {
				g_key_file_set_integer(mFile, "user", "indicatorOrientation", indicatorOrientation);
				saveFile();

				Taskbar::redraw();
			});

		forceIconSize.setup(g_key_file_get_boolean(mFile, "user", "forceIconSize", NULL),
			[](bool forceIconSize) -> void {
				g_key_file_set_boolean(mFile, "user", "forceIconSize", forceIconSize);
				saveFile();

				Taskbar::onPanelResize();
			});

		iconSize.setup(g_key_file_get_integer(mFile, "user", "iconSize", NULL),
			[](int iconSize) -> void {
				g_key_file_set_integer(mFile, "user", "iconSize", iconSize);
				saveFile();

				Taskbar::onPanelResize();
			});

		indicatorStyle.setup(g_key_file_get_integer(mFile, "user", "indicatorStyle", NULL),
			[](int indicatorStyle) -> void {
				g_key_file_set_integer(mFile, "user", "indicatorStyle", indicatorStyle);
				saveFile();

				Taskbar::redraw();
			});

		gchar* colorString = g_key_file_get_string(mFile, "user", "indicatorColor", NULL);
		GdkRGBA* color = (GdkRGBA*)malloc(sizeof(GdkRGBA));
		if (colorString == NULL || !gdk_rgba_parse(color, colorString))
			gdk_rgba_parse(color, "rgb(76,166,230)");

		indicatorColor.setup(color,
			[](GdkRGBA* indicatorColor) -> void {
				g_key_file_set_string(mFile, "user", "indicatorColor", gdk_rgba_to_string(indicatorColor));
				saveFile();

				Taskbar::redraw();
			});

		showWindowsListIfSingle.setup(g_key_file_get_boolean(mFile, "user", "showWindowsListIfSingle", NULL),
			[](bool showWindowsListIfSingle) -> void {
				g_key_file_set_boolean(mFile, "user", "showWindowsListIfSingle", showWindowsListIfSingle);
				saveFile();
			});

		onlyDisplayVisible.setup(g_key_file_get_boolean(mFile, "user", "onlyDisplayVisible", NULL),
			[](bool onlyDisplayVisible) -> void {
				g_key_file_set_boolean(mFile, "user", "onlyDisplayVisible", onlyDisplayVisible);
				saveFile();
			});

		onlyDisplayScreen.setup(g_key_file_get_boolean(mFile, "user", "onlyDisplayScreen", NULL),
			[](bool onlyDisplayScreen) -> void {
				g_key_file_set_boolean(mFile, "user", "onlyDisplayScreen", onlyDisplayScreen);
				saveFile();
			});

		keyComboActive.setup(g_key_file_get_boolean(mFile, "user", "keyComboActive", NULL),
			[](bool keyComboActive) -> void {
				g_key_file_set_boolean(mFile, "user", "keyComboActive", keyComboActive);
				saveFile();

				Hotkeys::updateSettings();
			});

		keyAloneActive.setup(g_key_file_get_boolean(mFile, "user", "keyAloneActive", NULL),
			[](bool keyAloneActive) -> void {
				g_key_file_set_boolean(mFile, "user", "keyAloneActive", keyAloneActive);
				saveFile();

				Hotkeys::updateSettings();
			});

		gchar** pinnedListBuffer = g_key_file_get_string_list(mFile, "user", "pinned", NULL, NULL);
		pinnedAppList.setup(Help::Gtk::bufferToStdStringList(pinnedListBuffer),
			[](std::list<std::string> list) -> void {
				std::vector<char*> buf = Help::Gtk::stdToBufferStringList(list);
				g_key_file_set_string_list(mFile, "user", "pinned", buf.data(), buf.size());
				saveFile();
			});
		g_strfreev(pinnedListBuffer);
	}

	void saveFile()
	{
		g_key_file_save_to_file(mFile, mPath.c_str(), NULL);
	}
} // namespace Settings