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
int doPrint(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);
int print_char(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_int(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
int flags, int width, int precision, int size);
int getFlags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);
int handleWriteChar(char c, char buffer[],
int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
int length, char padd, char extra_c);
int write_unsgnd(int is_negative, int ind, char buffer[],
int flags, int width, int precision, int size);
int isDigit(char);
int isPrintable(char);

#endif
