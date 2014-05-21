/*	types.h
	Defines macros for common types in bsos.
	Author: William Woodruff, Alex Gould (code migrated)
*/

#ifndef TYPES_H
#define TYPES_H

#define byte char

typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;

#define CHAR_SIZE     1 
#define SHORT_SIZE    2
#define INT_SIZE      4
#define LONG_SIZE     4 /* assume all longs are 32-bit until 64-bit mode asserted */
#define LONG_LONG_SIZE 8
#define PTR_SIZE      4 /* same logic as LONG_SIZE, assume 32-bit pts until asserted */
#define PTR_BITS      48
#define ADR_BITS      48
#define PAGE_SIZE_LOG2 12

#endif /* TYPES_H */