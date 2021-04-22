# xfce4-taskbar-plugin
A simple Taskbar for XFCE

![](https://github.com/mirkobrombin/xfce4-taskbar-plugin/blob/master/screenshot.png?raw=true)

## Building dependency
- libxfce4panel-2.0
- libxfce4ui-2
- gtk-3.0
- cairo-1.16
- libwnck-3.0

## Installation

### Arch Linux
Taskbar can be installed from the [official AUR package](https://aur.archlinux.org/packages/xfce4-taskbar-plugin-git/).

Ex. from yay AUR Helper:
```
yay -S xfce4-taskbar-plugin-git
```

### Other distribution
```
./autogen.sh
make
sudo make install
```

## Differences
- 'human' position for the pin/unpin button
- scales icons according to the size of the taskbar with a fixed margin
- hide (by default) the list of windows if there is only one

Based on nsz32/docklike plugin for XFCE.
