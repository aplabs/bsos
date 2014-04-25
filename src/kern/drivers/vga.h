/*	vga.h
	Function prototypes and macros for vga.c.
	Author: William Woodruff, 2014
*/

#ifndef VGA_H
#define VGA_H

#include "vga_constants.h"
#include "port_io.h"

int get_cursor(void);
void set_cursor(int offset);
int get_screen_offset(int row, int col);
void __write_str(char attr, const char* str);
void clear_screen(void);

#endif /* VGA_H */