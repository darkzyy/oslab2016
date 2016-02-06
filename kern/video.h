#ifndef _CONSOLE_H_
#define _CONSOLE_H_

#include <inc/assert.h>
#include <inc/types.h>
#include <inc/stdio.h>      //use NULL

#define SCR_WIDTH  320
#define SCR_HEIGHT 200
#define SCR_SIZE ((SCR_WIDTH) * (SCR_HEIGHT))
#define VMEM_ADDR  ((uint8_t*)(0xa0000 | 0xf0000000))

extern uint8_t *vmem;
extern uint8_t vbuf[];

static inline void
draw_pixel(int x, int y, int color) {
	assert(x >= 0 && y >= 0 && x < SCR_HEIGHT && y < SCR_WIDTH);
	vbuf[(x << 8) + (x << 6) + y] = color;
}

void prepare_buffer(void);
void display_buffer(void);

void draw_string(const char*, int, int, int);

#endif
