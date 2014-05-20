/*	kern_constants.h
	Defines constants for memory management.
	Authors: Pawel Czarnecki (VinnyOG) and Alex Gould (lyra833)
*/

#ifndef KERN_CONSTANTS_H
#define KERN_CONSTANTS_H

//all sizes in byes

#define STACK_SIZE 8192    //8Kb, should be increased later
#define INIT_MAT_SIZE 1024   //1024 entries into the Memory Allocation Table

#define CHAR_SIZE     1 //We're using x86 architecture, so I thought it would be a good idea to put these in.
#define SHORT_SIZE    2
#define INT_SIZE      4
#define LONG_SIZE     8
#define LONG_SIZE_LOG2 3
#define LONG_LONG_SIZE 8
#define PTR_SIZE      8
#define PTR_BITS      48
#define ADR_BITS      48
#define PAGE_SIZE_LOG2 12

#endif /* KERN_CONSTANTS_H */
