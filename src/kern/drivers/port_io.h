/*	port_io.h
	Function prototypes for port_io.c.
	Author: William Woodruff, 2014
*/

#ifndef PORT_IO_H
#define PORT_IO_H

/* input */
unsigned char port_byte_in(unsigned short port);
unsigned short port_word_in(unsigned short port);

/* output */
void port_byte_out(unsigned short port, unsigned char data);
void port_word_out(unsigned short port, unsigned short data);

#endif /* PORT_IO_H */