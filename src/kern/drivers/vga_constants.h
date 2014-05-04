/*	vga_constants.h
	Defines constants for VGA operation.
	Author: William Woodruff, 2014
*/

#ifndef VGA_CONSTANTS_H
#define VGA_CONSTANTS_H

#define VIDEO_MEMORY 0xb8000
#define REG_SCREEN_CTRL 0x3d4
#define REG_SCREEN_DATA 0x3d5

/* dimensions */
#define VGA_ROWS 25
#define VGA_COLS 80

/* colors */
#define BLACK 0x0
#define BLUE 0x1
#define GREEN 0x2
#define CYAN 0x3
#define RED 0x4
#define MAGENTA 0x5
#define BROWN 0x6
#define LGRAY 0x7
#define DGRAY 0x8
#define LBLUE 0x9
#define LGREEN 0xA
#define LCYAN 0xB
#define LRED 0xC
#define LMAGENTA 0xD
#define LBROWN 0xE
#define WHITE 0xF

/* Special Characters */
#define NEWLINE 0xA

/* ORs two nibbles to create a color attribute */
#define COLOR_ATTR(fg, bg) ((char) ((bg << 3) | (1 << 4) | (fg >> 4)))

#endif /* VGA_CONSTANTS_H */
