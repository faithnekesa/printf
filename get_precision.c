#include "main.h"

/**
 * get_precision_param -Extracts the precision param to be printed
 * @format: The formatted string
 * @index: Arguments to be printed.
 * @list: Argument list
 *
 * Return: The precision param
 */
int get_precision_param(const char *format, int *index, va_list list)
{
	int this_index = *index + 1;
	int prec_param = -1;

	if (format[this_index] != '.')
		return (prec_param);

	prec_param = 0;

	for (this_index += 1; format[this_index] != '\0'; this_index++)
	{
		if (is_digit(format[this_index]))
		{
			prec_param *= 10;
			prec_param += format[this_index] - '0';
		}
		else if (format[this_index] == '*')
		{
			this_index++;
			prec_param = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*index = this_index - 1;

	return (prec_param);
}
