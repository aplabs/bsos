/*	vga.c
	Defines a basic driver and functions for VGA output.
	Author: William Woodruff, 2014
*/

#include "vga.h"

/*	get_cursor
	get the current offset of the cursor in memory
*/
int get_cursor(void)
{
	port_byte_out(REG_SCREEN_CTRL, 0x0e);
	int offset = port_byte_in(REG_SCREEN_DATA) << 8;
	port_byte_out(REG_SCREEN_CTRL, 0x0f);
	offset += port_byte_in(REG_SCREEN_DATA);

	return offset * 2;
}

/*	set_cursor
	set the position of the cursor to the given offset
*/
void set_cursor(int offset)
{
	offset /= 2;
	port_byte_out(REG_SCREEN_CTRL, 0x0f);
	port_byte_out(REG_SCREEN_DATA, (unsigned char) offset & 0xff);
	port_byte_out(REG_SCREEN_CTRL, 0x0e);
	port_byte_out(REG_SCREEN_DATA, (unsigned char) ((offset >> 8) & 0xff));
}

/*	get_screen_offset
	return the memory offset representative of the given VGA row/column pair
*/
int get_screen_offset(int row, int col)
{
	return ((row * 80) + col) * 2;
}

/*	__write_str
	write a null-terminated string to the screen, setting the cursor after the string
*/
void __write_str(char attr, const char* str)
{
	unsigned char* video_memory = (unsigned char*) VIDEO_MEMORY;

	while (*str)
	{
		*video_memory++ = *str++;
		*video_memory++ = attr;
	}


	set_cursor((int) (video_memory - VIDEO_MEMORY));
}

/*	__print_str
	do the same as __write_str, but prints at the cursor location
	and new line with '\n' character
*/
void __print_str(char attr, const char* str)
{
	unsigned char* video_memory = (unsigned char*) VIDEO_MEMORY;
	video_memory += get_cursor();

	while (*str)
	{
		if(*str == NEWLINE)
		{
			int offset = (int) (video_memory - VIDEO_MEMORY);
			offset = offset % (VGA_COLS * 2);
			offset = (VGA_COLS * 2) - offset;
			video_memory += offset;
			str++;
		}else{
		*video_memory++ = *str++;
		*video_memory++ = attr;
		}
	}


	set_cursor((int) (video_memory - VIDEO_MEMORY));
}

/*	clear_screen
	clear the screen entirely, setting the cursor to the top left corner
*/
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
