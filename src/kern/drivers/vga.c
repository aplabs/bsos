/*	vga.c
	Defines a basic driver and functions for VGA output.
	Author: William Woodruff, 2014
*/

#include "vga.h"

int get_cursor(void)
{
	port_byte_out(REG_SCREEN_CTRL, 0x0e);
	int offset = port_byte_in(REG_SCREEN_DATA) << 8;
	port_byte_out(REG_SCREEN_CTRL, 0x0f);
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
	return ((row * 80) + col) * 2;
}

void __write_str(char attr, const char* str)
{
	unsigned char* video_memory = (unsigned char*) VIDEO_MEMORY;

	while (*str)
	{
		*video_memory++ = *str++;
		*video_memory++ = attr;
	}

	int offset = ((int) video_memory) - VIDEO_MEMORY;
	set_cursor(offset);
}

void clear_screen(void)
{
	unsigned char* video_memory = (unsigned char*) VIDEO_MEMORY;

	for (int i = 0; i < 2000; i++)
	{
		*video_memory++ = ' ';
		*video_memory++ = 0x0F;
	}

	set_cursor(get_screen_offset(0, 0));
}