#include <kern/video.h>
#include <inc/string.h>

uint8_t *vmem = VMEM_ADDR;
uint8_t vbuf[SCR_SIZE];

void 
prepare_buffer(void) {
	memset(vbuf, 0, SCR_SIZE);
}

void
display_buffer(void) {
	log3();
	vmem = VMEM_ADDR;
	memmove(vmem, vbuf, SCR_SIZE);
}

void
draw_square(int y, int x, int color, int len) {
	log3();
	assert(len >= 0);
	int i,j;
	for(j = 0;j < len;j++) {
		for(i = 0;i < len;i++) {
			draw_pixel(x+i, y+j, color);
		}
	}
}
