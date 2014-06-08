//Flash.c
//Contains methods for dealing with Flash memory directly.
//Alex Gould
//(Working with other people's headers is like building with Legos! I feel like I'm doing Scratch again!)

#include <Includes.h>
#include "flash.h"

void start(void)
{
   SI32_CLKCTRL_A_enable_apb_to_modules_0(SI32_CLKCTRL_0, SI32_CLKCTRL_A_APBCLKG0_FLCTRLCEN_ENABLED_U32);
   SI32_VMON_A_enable_vdd_supply_monitor(SI32_VMON_0);
   SI32_RSTSRC_A_enable_vdd_monitor_reset_source(SI32_RSTSRC_0);
}

void clear(unsigned int addr)
{
	while(SI32_FLASHCTRL_A_is_buffer_full(SI32_FLASHCTRL_0) == true)
	{
	SI32_FLASHCTRL_A_exit_multi_byte_write_mode(SI32_FLASHCTRL_0);
	SI32_FLASHCTRL_A_write_wraddr(SI32_FLASHCTRL_0, addr);
	SI32_FLASHCTRL_A_enter_flash_erase_mode(SI32_FLASHCTRL_0);
	SI32_FLASHCTRL_A_write_flash_key(SI32_FLASHCTRL_0, 0xA5);
	SI32_FLASHCTRL_A_write_flash_key(SI32_FLASHCTRL_0, 0xF1);
	SI32_FLASHCTRL_A_write_wrdata(SI32_FLASHCTRL_0, 0x0000);
	}
}

int write(unsigned char * c,unsigned int addr, unsigned int num)
{
   int i;
   unsigned short *buf = (unsigned short*)c;
   SI32_FLASHCTRL_A_exit_flash_erase_mode(SI32_FLASHCTRL_0);
   SI32_FLASHCTRL_A_write_wraddr(SI32_FLASHCTRL_0, addr);
   SI32_FLASHCTRL_A_enter_multi_byte_write_mode(SI32_FLASHCTRL_0);
   SI32_FLASHCTRL_A_write_flash_key(SI32_FLASHCTRL_0, 0xA5);
   SI32_FLASHCTRL_A_write_flash_key(SI32_FLASHCTRL_0, 0xF2);
   for(i = 0; i < num / 2; i++)
   {
      SI32_FLASHCTRL_A_write_wrdata(SI32_FLASHCTRL_0, buf[i]);
      while(SI32_FLASHCTRL_A_is_flash_busy(SI32_FLASHCTRL_0));
   }
   return 0;
}
