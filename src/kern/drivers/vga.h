/*	vga.h
	Function prototypes and macros for vga.c.
	Author: William Woodruff, 2014
*/

#ifndef VGA_H
#define VGA_H

#include "vga_constants.h"
#include "port_io.h"

void printch(char ch);
void prints(char* str);
void __print_binary(char attr, unsigned char c);
void __print_hex(char attr, unsigned char c);
void clear_screen(void);

#endif /* VGA_H */
