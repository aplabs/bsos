/*	port_io.c
	Handles low-level port I/O on memory-mapped devices.
	Author: William Woodruff, 2014
*/

/*	port_byte_in
	read a byte from the given port
*/
unsigned char port_byte_in(unsigned short port)
{
	unsigned char value;
	__asm__(
		"in %%dx, %%al" :
		"=a" (value) :
		"d" (port)
		);
	return value;
}

/*	port_word_in
	read a word (short) from the given port
*/
unsigned short port_word_in(unsigned short port)
{
	unsigned short value;
	__asm__(
		"in %%dx, %%ax" :
		"=a" (value) :
		"d" (port)
		);
	return value;
}

/*	port_byte_out
	send the given byte to the given port
*/
void port_byte_out(unsigned short port, unsigned char data)
{
	__asm__(
		"out %%al, %%dx" : :
		"a" (data),
		"d" (port)
		);
}

/*	port_word_out
	send the given word (short) to the given port
*/
void port_word_out(unsigned short port, unsigned short data)
{
	__asm__(
		"out %%ax, %%dx" : :
		"a" (data),
		"d" (port)
		);
}