/*	memory_segment.h
	Defines a struct responsible for the address, size, and relative position of a memory segment.
	Author: Pawel Czarnecki

	Notes:
	This file defines, on the kernel level, what a segment is and what properties it has
	The idea is that the kernel will be able to summon new pages/segments on demand \
	and this is the structure that will define these regions
*/

struct __memory_segment{
  unsigned int real_address;
  unsigned int real_size;
  unsigned int distance_to_next_segment;
};
