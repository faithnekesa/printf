#include "main.h"
/**
 * print_op - Prints an argument based on its type
 * @format: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @precision_param: Precision passed by user
 * Return: 1 or -1 if unsuccessful;
 */
int print_op(const char *format, va_list list, int precision_param)
{
	printed_chars = -1;
	format_t format_types[] = {
		{'c', printChar},
		{'s', printString},
		{'%', printPercent},
		{'\0', NULL}
	};
	return (printed_chars);
}
