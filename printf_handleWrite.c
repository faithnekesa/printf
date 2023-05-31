#include "main.h"
/**
 * doPrint -Function that prints function based on precision
 * @fmt:String formatted to prints args
 * @list: List of arguments to be printed.
 * @index: index
 * @buffer: Buffer array to handle print.
 * @flags:checks the active flags
 * @width: gets the width
 * @precision: Precision specifier
 * @size: Size of specifier
 * Return: 1 or 2;
 */
int doPrint(const char *fmt, int *index, va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
	int newLen = 0, counter = 0, charsPrinted = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'\0', NULL}
	};
	for (counter = 0; fmt_types[counter].fmt != '\0'; counter++)
		if (fmt[*index] == fmt_types[counter].fmt)
			return (fmt_types[counter].func(list, buffer, flags,
						width, precision, size));
	if (fmt_types[counter].fmt == '\0')
	{
		if (fmt[*index] == '\0')
			return (-1);
		newLen += write(1, "%%", 1);
		if (fmt[*index - 1] == ' ')
			newLen += write(1, " ", 1);
		else if (width)
		{
			--(*index);
			while (fmt[*index] != ' ' && fmt[*index] != '%')
			--(*index);
			if (fmt[*index] == ' ')
			--(*index);
			return (1);
		}
		newLen += write(1, &fmt[*index], 1);
		return (newLen);
	}
	return (charsPrinted);
}
