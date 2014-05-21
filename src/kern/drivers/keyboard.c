/*	keyboard.c
	Oh my God, this is the worst code I have ever written. But, hey, it seems to compile.
	Please don't kill me...
	Author: Alex Gould (lyra833)
*/

#include <keyboard.h>

extern void *irqvec[];

static struct keyboard keyboard __attribute__ ((__aligned__(4K))); //I have no idea if this number is right...
#define newKey(hex)                                             \
    (((((hex) >> 8) & 0xff) == 0xf0)                         \
     ? (keyboard.keytabup[hex >> 16] = hex##_SYM | 0x80)       \
     : ((((hex) & 0xff) == 0xe0)                         \
        ? (keyboard.keytabmb[hex >> 8] = hex##_SYM,                     \
           keyboard.keytabup[hex >> 8] = hex##_SYM | 0x80)     \
        : (keyboard.keytab1b[hex] = hex##_SYM,                          \
           keyboard.keytabup[hex] = hex##_SYM | 0x80)))

inline void startKeyboard(void)
{
    uint8_t u8;
    __asm__ ("outb %%b0, %%w1\n" : : "a" (0xf4), "Nd" (0x60));
    do {
        __asm__ ("inb %%w1, %%b0\n" : "=a" (u8) : "Nd" (0x60));
    } while (u8 != 0xfa);
    __asm__ ("outb %%b0, %%w1\n" : : "a" (0xf0), "Nd" (0x60));
    do {
        __asm__ ("inb %%w1, %%b0\n" : "=a" (u8) : "Nd" (0x60));
    } while (u8 != 0xfa);
    __asm__ ("outb %%b0, %%w1\n" : : "a" (0x01), "Nd" (0x60));
    do {
        __asm__ ("inb %%w1, %%b0\n" : "=a" (u8) : "Nd" (0x60));
    } while (u8 != 0xfa);
    mapKeys();
    irqvec[IRQKBD] = interrupt;

    return;
}

void mapKeys(void)
{
    for (int i = FirstKey; i <= LastKey; ++i)
	{
        newKey((KEYCODES)i); //Oops. [it used to be "new Key"
    }
    return;
}

void interrupt(void)
{
    uint64_t keycode = 0;
    int32_t  isup = 0;
    int32_t  val;
    uint8_t  u8;
    val = 0;
    __asm__ ("inb %%w1, %%b0\n" : "=a" (u8) : "Nd" (0x60));
    if (u8 == 0xe1) //Pause
	{
        __asm__ ("inb %%w1, %%b0\n" : "=a" (u8) : "Nd" (0x60));
        keycode = 0x1d;
        __asm__ ("inb %%w1, %%b0\n" : "=a" (u8) : "Nd" (0x60));
        keycode |= UINT64_C(0x45) << 8;
        __asm__ ("inb %%w1, %%b0\n" : "=a" (u8) : "Nd" (0x60));
        keycode |= UINT64_C(0xe1) << 16;
        __asm__ ("inb %%w1, %%b0\n" : "=a" (u8) : "Nd" (0x60));
        keycode |= UINT64_C(0x9d) << 24;
        __asm__ ("inb %%w1, %%b0\n" : "=a" (u8) : "Nd" (0x60));
        keycode |= UINT64_C(0xc5) << 32;
        u8 &= 0xff;
        val = keyboard.keytab1b[u8];
    }
	else if (u8 != 0xe0)
	{
        if (u8 & 0x80) //Release
		{
            keycode = u8;
            isup = 1;
            u8 &= ~0x80;
            val = keyboard.keytabup[u8];
        } else {
            val = keyboard.keytab1b[u8];
        }
    } else
	{
        __asm__ ("inb %%w1, %%b0\n" : "=a" (u8) : "Nd" (0x60));
        keycode = 0xe0;
        keycode |= (uint64_t)u8 << 8;
        if (u8 == 0x2a || u8 == 0x46)
		{
            __asm__ ("inb %%w1, %%b0\n" : "=a" (u8) : "Nd" (0x60)); /* 0xe0 */
            keycode |= (uint64_t)u8 << 16;
            __asm__ ("inb %%w1, %%b0\n" : "=a" (u8) : "Nd" (0x60)); /* 0x37 (prtsc) or 0xc6 (ctrl-pause) */
            keycode |= (uint64_t)u8 << 24;
            val = keyboard.keytabmb[u8];
        } else if (u8 == 0x80)
		{
            keycode = u8;
            __asm__ ("inb %%w1, %%b0\n" : "=a" (u8) : "Nd" (0x60));
            keycode = (uint64_t)u8 << 8;
            val = keyboard.keytabup[u8];
        } else
		{
            if (u8 & 0x80) {
                isup = 1;
                u8 &= ~0x80;
                val = keyboard.keytabup[u8];
            } else
			{
                val = keyboard.keytabmb[u8];
            }
        }
    }
    addKey(keycode, val);

    return;
}
