ACLOCAL_AMFLAGS = -I m4  ${ACLOCAL_FLAGS}

SUBDIRS = src po

distclean-local:
	rm -rf *.cache *~

EXTRA_DIST = AUTHORS LICENCE intltool-extract.in intltool-merge.in intltool-update.in

<<<<<<< HEAD
# Installing the plugin's desktop file in the correct place
#desktopdir = $(datadir)/xfce4/panel/plugins
#desktop_DATA = $(PACKAGE_NAME).desktop

#
# Desktop file
#
desktopdir = $(datadir)/xfce4/panel/plugins
desktop_in_files = taskbar.desktop
desktop_DATA = $(desktop_in_files)

EXTRA_DIST = $(desktop_in_files)

# Clean generated files
#CLEANFILES = $(desktop_DATA)
=======
DISTCLEANFILES =				\
	aclocal.m4					\
	compile						\
	configure					\
	configure.ac				\
	depcomp						\
	install-sh					\
	ltmain.sh					\
	missing						\
	mkinstalldirs				\
	intltool-extract			\
	intltool-merge				\
	intltool-update
>>>>>>> mirai-patch/master
