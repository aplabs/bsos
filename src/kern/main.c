/*	main.c
	The entry point of the OS. 
	Author: William Woodruff
*/

#include "drivers/vga.h"

void main(void)
{
	//__print_char('X', 0, 0, COLOR_ATTR(WHITE, BLACK));
	//__write_str((char) 0x7, "test");
	__write_str(COLOR_ATTR(WHITE, BLACK), "test123456");
}
