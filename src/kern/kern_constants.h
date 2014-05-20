/*	kern_constants.h
	Defines constants for memory management.
	Author: Pawel Czarnecki (VinnyOG) and Alex Gould (lyra833)
*/

#ifndef KERN_CONSTANTS_H
#define KERN_CONSTANTS_H

//all sizes in byes

#define STACK_SIZE 8192    //8Kb, should be increased later
#define INIT_MAT_SIZE 1024   //1024 entries into the Memory Allocation Table

#define CHARSIZE     1 //We're using x86 architecture, so I thought it would be a good idea to put these in.
#define SHORTSIZE    2
#define INTSIZE      4
#define LONGSIZE     8
#define LONGSIZELOG2 3
#define LONGLONGSIZE 8
#define PTRSIZE      8
#define PTRBITS      48
#define ADRBITS      48
#define PAGESIZELOG2 12

#endif /* KERN_CONSTANTS_H */
