/*	Mouse.h
	Author: Alex Gould (lyra833)
	This file contains some basic values and networking functions for a PS/2 mouse. It's nowhere near done.
	TO DO:
		Include a struct with some common values and constructors
		Add some common network functions
	NOT AS IMPORTANT:
		Add manufacturer specific commands
*/

#ifndef MOUSE_H
#define MOUSE_H

enum states
{
	DORMANT,
	INITIALIZING,
	ACTIVATED,
	RESYNCING,
};

enum mouseCommands //Kindly provided by http://www.win.tue.nl/~aeb/linux/kbd/scancodes-13.html
{
	SECONDARYID = 0x00e1
	SETSCALE11 = 0x00e6
	SETSCALE21 = 0x00e7
	SETRES = 0x10e8
	GETINFO = 0x03e9
	SETSTREAM = 0x00ea
	SETPOLL = 0x00f0
	POLL = 0x00eb	//Depending on the type of mouse, we might need to request different signal lengths in the .c files.
	RESET_WRAP = 0x00ec
	CMD_GETID = 0x02f2
	SETRATE = 0x10f3
	ENABLE = 0x00f4
	DISABLE = 0x00f5
	RESET_DIS = 0x00f6
	RESET_BAT = 0x02ff
};
#endif /* MOUSE_H */