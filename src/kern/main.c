/*	main.c
	The entry point of the OS. 
	Author: William Woodruff
*/

#define VIDEO_ADDRESS 0xb8000
#define VGA_ROWS 25
#define VGA_COLS 80
#define WHITE_ON_BLACK 0x0f

void main(void)
{
	char* video_memory = (char*) VIDEO_ADDRESS;
	*video_memory = 'Y';
}