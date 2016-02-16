/* See COPYRIGHT for copyright information. */

#ifndef JOS_KERN_TRAP_H
#define JOS_KERN_TRAP_H
#ifndef JOS_KERNEL
# error "This is a JOS kernel header; user programs should not #include it"
#endif

#include <inc/trap.h>
#include <inc/mmu.h>

/* The kernel's interrupt descriptor table */
extern struct Gatedesc idt[];
extern struct Pseudodesc idt_pd;

void trap_init(void);
void trap_init_percpu(void);
void print_regs(struct PushRegs *regs);
void print_trapframe(struct Trapframe *tf);
void page_fault_handler(struct Trapframe *);
void backtrace(struct Trapframe *);

extern char* vec0[];
extern char* vec1[];
extern char* vec2[];
extern char* vec3[];
extern char* vec4[];
extern char* vec5[];
extern char* vec6[];
extern char* vec7[];
extern char* vec8[];

extern char* vec10[];
extern char* vec11[];
extern char* vec12[];
extern char* vec13[];
extern char* vec14[];

extern char* vec16[];
extern char* vec17[];
extern char* vec18[];
extern char* vec19[];

extern char* vec48[];
extern char* vecall[];

extern char* irq_0[];
extern char* irq_1[];
extern char* irq_2[];
extern char* irq_3[];
extern char* irq_4[];
extern char* irq_5[];
extern char* irq_6[];
extern char* irq_7[];
extern char* irq_8[];
extern char* irq_9[];
extern char* irq_10[];
extern char* irq_11[];
extern char* irq_12[];
extern char* irq_13[];
extern char* irq_14[];
extern char* irq_15[];
extern char* irq_16[];
extern char* irq_17[];
extern char* irq_18[];
extern char* irq_19[];
#endif /* JOS_KERN_TRAP_H */
