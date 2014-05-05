/*	segment_store.c
	Defines functions for managing memory segments.
	Author: Pawel Czarnecki
*/

#include "../kern_constants.h"

//function prototypes (to be put into own header file)

int __insert_segment(struct* __memory_segment);
int __free_address(void* __address);


struct __Memory_Allocation_Table{
  void* _indices[INIT_MAT_SIZE + 1];     //the last index holds the location of the next MAT
  void* _entries[INIT_MAX_SIZE * BLOCK_SIZE]
  unsigned int _num_entries = 0;
  unsigned int _last_free_slot = 0;  //the last location freed will be the first one used, set to _num_entries once used
} __init_MAT;


/*
   Ideally it should be inserted to keeop the order of the addresses in line
*/
int __insert_segment(struct* __memory_segment){
   if(__num_entries == INIT_MAX_SIZE)     //we have reached our limit
     return -1;
     
     
     //insert_index should be selected based on order of real addresses
     //insert_segemnt should be the last freed slot or at the very end
   unsigned int insert_index = __num_entries;
   unsigned int insert_segment = _last_free_slot != _num_entires ? _last_free_slot : _num_entries;
   _last_free_slot = _num_entries
   __init_MAT._indices[insert_index] = 
   
   
}
