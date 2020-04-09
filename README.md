Simple Taskbar for XFCE
-----------------------------------

![taskbar-plugin](https://i.imgur.com/6HNLRLI.png)

Taskbar will be published in the ArchLinux User Repository (AUR)!

Installation instructions :
```
# For ArchLinux users :
yay -S xfce4-taskbar-plugin-git

# On any other distro :
./autogen.sh
make
sudo make install
```

Building dependency :
libxfce4panel-2.0
libxfce4ui-2
gtk-3.0
cairo-1.16
libwnck-3.0


Based on nsz32/docklike-plugin original work.