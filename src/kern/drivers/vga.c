/*	vga.c
	Defines a basic driver and functions for VGA output.
	Author: William Woodruff, Brian Hong, 2014
*/

#include "vga.h"

unsigned char* video_memory = (unsigned char*) VIDEO_MEMORY;
unsigned short cursor_pos = 0;

void printch(char ch)
{
	video_memory[cursor_pos * 2] = ch;
	cursor_pos++;
}

void prints(char* str)
{
	while (*str)
	{
		printch(*str);
		str++;
	}
}

/*	__print_binary
	prints binary representation of the input byte
*/
void __print_binary(char attr, unsigned char b){
	char* str = "0b22222222"; 
	char* loc = str++; //offset since beginning has 0b
	
	for(int i = 7; i >= 0; i--)
	{
		int a = b & (1 << i);
		if(a == 0)
			*++str = '0';
		else
			*++str = '1';
	}
	prints(loc);
}

/*	__print_hex
	prints hex representation of the input byte
*/
void __print_hex(char attr, unsigned char b){
	char* str = "0x00"; //placeholder for size
	char* loc = str++; //offset since beginning has 0x
	
char key[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

	int u = ((b & 0xf0) >> 4);
	int l = (b & 0x0f);
	*++str = key[u];
	*++str = key[l];

	//*++str = '\n'; //newline
	prints(loc);
}

/*	clear_screen
	clear the screen entirely, setting the cursor to the top left corner
*/
void clear_screen(void)
{
	for (int i = 0; i <= 8000; i += 2)
	{
		video_memory[i] = ' ';
	}
}
