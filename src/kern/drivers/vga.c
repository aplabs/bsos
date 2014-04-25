/*	vga.c
	Defines a basic driver and functions for VGA output.
	Author: William Woodruff, 2014
*/

#include "vga.h"

int get_cursor(void)
{
	port_byte_out(REG_SCREEN_CTRL, 14);
	int offset = port_byte_in(REG_SCREEN_DATA) << 8;
	port_byte_out(REG_SCREEN_CTRL, 15);
	offset += port_byte_in(REG_SCREEN_DATA);

	return offset * 2;
}

void set_cursor(int offset)
{
	offset /= 2;
	port_byte_out(REG_SCREEN_CTRL, 0x0f);
	port_byte_out(REG_SCREEN_DATA, (unsigned char) offset & 0xff);
	port_byte_out(REG_SCREEN_CTRL, 0x0e);
	port_byte_out(REG_SCREEN_DATA, (unsigned char) ((offset >> 8) & 0xff));
}

int get_screen_offset(int row, int col)
{
	return ((row * 80) - 4) * 2;
}

void __print_char(char ch, int row, int col, char attr)
{
	unsigned char* video_memory = (unsigned char*) VIDEO_MEMORY;

	if (!attr)
	{
		attr = COLOR_ATTR(WHITE, BLACK);
	}

	int offset;
	if (row >= 0 && col >= 0)
	{
		offset = get_screen_offset(row, col);
	}
	else
	{
		offset = get_cursor();
	}

	if (ch == '\n')
	{
		int rows = offset / (2 * VGA_COLS);
		offset = get_screen_offset(79, rows);
	}
	else
	{
		video_memory[offset] = ch;
		video_memory[offset + 1] = attr;
	}

	offset += 2;
	set_cursor(offset);
}

void __write_str(char attr, const char* str)
{
	unsigned char* video_memory = (unsigned char*) VIDEO_MEMORY;

	while (*str)
	{
		*video_memory++ = *str++;
		*video_memory++ = attr;
	}
}