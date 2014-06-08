#ifndef __FLASH_H__
#define __FLASH_H__
#include <stdbool.h>

void clear(unsigned int addr);
int write(unsigned char* buf,unsigned int addr, unsigned int num);
void start(void);
#endif
