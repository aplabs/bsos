/*	main.c
	The entry point of the OS. 
	Loaded by boot.asm.
	Author: William Woodruff
*/

void main(void)
{
	char* video_memory = (char*) 0xb8000;
	*video_memory = 'X';
}