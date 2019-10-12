# Auto-clicker

Easy to use, one-button-triggered autoclicker

---

## __REQUIREMENTS__

Requirement list:
1) Windows x86/x64 operating system
2) Mingw GNU compiler (download -> https://sourceforge.net/projects/mingw/)

---

## __BUILD__

To build project, simply execute `AutoMake.bat` script. Target executable is named `autoclicker.exe` by default.

---

## __USAGE GUIDE__

Please configure the autoclicker's control as following:

1) Default control is: `middle mouse key` for trigger, `G` for mode switching, `1` for left click, `2` for right click
2) To adjust controls to your likings, config/keyconf.conf under same directory as AutoClick.exe, and open with preferred text editor
3) Four options in _keyconf.conf_:
	- trigger: trigger of autoclicker
	- mode: alternate between two clicking modes - the "finger jesus" (10ms/click) or the "human Seizes" (100ms~180ms/click)
	- left: left mouse button
	- right: right mouse button
4) Change the controls by changing the settings to the right of ":". Support single charactors (`0~9`, `A-Z`(must be caps!)), left shift (`lshift`), left control (`lctrl`), and middle mouse button (`mmiddle`). example setting:
	- trigger:J
	- mode:I
	- left:lshift
	- right:lctrl
5) Please respect the config file format and do not fk w/ it, otherwise fam you finna have to comeback to check on this README again


Anyway have fun doing legal things widit.
