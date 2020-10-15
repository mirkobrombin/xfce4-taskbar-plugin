# xfce4-taskbar-plugin
A simple Taskbar for XFCE

## Building dependency
- libxfce4panel-2.0
- libxfce4ui-2
- gtk-3.0
- cairo-1.16
- libwnck-3.0

## Installation
```
./autogen.sh
make
sudo make install
```

## Differences
- 'human' position for the pin/unpin button
- scales icons according to the size of the taskbar with a fixed margin
- hide (by default) the list of windows if there is only one

Based on nsz32/docklike.