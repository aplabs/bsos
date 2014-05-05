/* segment_store.c will define code that keeps track of kernel-defined memory segments
   -Pawel
*/
#include "kern_constants"

int __insert_segment(struct* __memory_segment);

struct __Memory_Allocation_Table{
  void* _indices[INIT_MAT_SIZE]; 
  void* _entries[INIT_MAX_SIZE * BLOCK_SIZE]
};

