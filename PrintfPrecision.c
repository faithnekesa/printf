#include "main.h"

/**
 * get_precision -Precision specifier to be printed
 * @format: Stringformatted to print arguments
 * @argList:Argument list to be printed
 * @list:Argument list
 * Return:the precision
 */
int get_precision(const char *format, int *argList, va_list list)
{
	int this_index = *argList + 1;
	int precision = -1;

	if (format[this_index] != '.')
		return (precision);

	precision = 0;

	for (this_index += 1; format[this_index] != '\0'; this_index++)
	{
		if (isDigit(format[this_index]))
		{
			precision *= 10;
			precision += format[this_index] - '0';
		}
		else if (format[this_index] == '*')
		{
			this_index++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*argList = this_index - 1;

	return (precision);
}

