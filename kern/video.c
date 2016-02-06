#include <kern/video.h>
#include <inc/string.h>

uint8_t *vmem = VMEM_ADDR;
static uint8_t vbuf[SCR_SIZE];

void 
prepare_buffer(void) {
	memset(vbuf, 0, SCR_SIZE);
}

void
display_buffer(void) {
	vmem = VMEM_ADDR;
	memmove(vmem, vbuf, SCR_SIZE);
}
