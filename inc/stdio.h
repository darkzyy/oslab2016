#ifndef JOS_INC_STDIO_H
#define JOS_INC_STDIO_H

#include <inc/stdarg.h>

#ifndef NULL
#define NULL	((void *) 0)
#endif /* !NULL */

// lib/stdio.c
void	cputchar(int c);
int	getchar(void);
int	iscons(int fd);

// lib/printfmt.c
void	printfmt(void (*putch)(int, void*), void *putdat, const char *fmt, ...);
void	vprintfmt(void (*putch)(int, void*), void *putdat, const char *fmt, va_list);
int	snprintf(char *str, int size, const char *fmt, ...);
int	vsnprintf(char *str, int size, const char *fmt, va_list);

// lib/printf.c
int	cprintf(const char *fmt, ...);
int	vcprintf(const char *fmt, va_list);

// lib/fprintf.c
int	printf(const char *fmt, ...);
int	fprintf(int fd, const char *fmt, ...);
int	vfprintf(int fd, const char *fmt, va_list);

// lib/readline.c
char*	readline(const char *prompt);

// debug:
#define log2(format,...)	\
	do {\
		cprintf("LAB2:\t"format"\tin %s,function %s, line: %d\n",\
		##__VA_ARGS__,__FILE__,__func__,__LINE__);\
	} while(0)

#define log3(format,...)	\
	do {\
		cprintf("LAB3:\t"format"\tin %s,function %s, line: %d\n",\
		##__VA_ARGS__,__FILE__,__func__,__LINE__);\
	} while(0)

#define log4(format,...)	\
	do {\
		cprintf("LAB4:\t"format"\tin %s,function %s, line: %d\n",\
		##__VA_ARGS__,__FILE__,__func__,__LINE__);\
	} while(0)

#define log_var(x) \
    do {\
        log4("variable " #x " is 0x%x",x);\
    } while(0)

#define dead() \
    do {\
    } while(1)

#endif /* !JOS_INC_STDIO_H */
