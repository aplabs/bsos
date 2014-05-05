/* This file defines, on the kernel level, what a segment is and what properties it has
   The idea is that the kernel will be able to summon new pages/segments on demand \
   and this is the structure that will define these regions
*/

struct __memory_segment{
  unsigned long absolute_address;
};
