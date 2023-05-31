#ifndef PRINTF_H
#define PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* Macro for flags */
#define F_SPACE_ 16
#define F_HASH_ 8
#define F_PLUS_ 2
#define F_ZERO_ 4
#define F_MINUS_ 1

/* Macro for size*/
#define S_LONG_ 2
#define S_SHORT_ 1

/**
 * struct fmt - Struct op
 * @fmt: The format.
 * @func: The function associated
 */

struct fmt
{
	char fmt;
	int (*func)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - Struct op
 * @fmt: The format
 *  @fm_t: The function associated
 *
 */

typedef struct fmt fmt_t;
int _printf(const char *format, ...);


#endif
