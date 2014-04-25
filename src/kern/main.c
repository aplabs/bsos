/*	main.c
	The entry point of the OS. 
	Author: William Woodruff
*/

#include "drivers/vga.h"

void main(void)
{
	clear_screen();
	__write_str(COLOR_ATTR(WHITE, BLACK), "Loading...");
}
