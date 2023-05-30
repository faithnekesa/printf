#ifndef PRINTF_H
#define PRINTF_H
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int _printf(const char *format, ...);
int print_op(const char *format, va_list list, int precision_param);
int get_precision_param(const char *format, int *index, va_list list);
int printChar(va_list list, int precision_param);
int printString(va_list list, int precision_param);
int printPercent(va_list list,int precision_param);

#endif
