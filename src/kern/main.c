/*	main.c
	The entry point of the OS. 
	Author: William Woodruff
*/

#include "drivers/vga_constants.h"

void main(void)
{
	char* video_memory = (char*) VIDEO_ADDRESS;
	*video_memory = 'Y';
}
