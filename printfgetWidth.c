#include "main.h"

/**
 * getWidth - Gets the width for printing
 * @format:String formatted to print arguments
 * @counter: Argument list to be printed
 * @list:Number of charactters printed
 *
 * Return: the width.
 */

int getWidth(const char *format, int *counter, va_list list)
{
	int this_index;
	int width = 0;

	for (this_index = *counter + 1; format[this_index] != '\0'; this_index++)
	{
		if (isDigit(format[this_index]))
		{
			width = width * 10;
			width = width + format[this_index] - '0';
		}
		else if (format[this_index] == '*')
		{
			this_index++;
			width = va_arg(list, int);
			break;
		}
		else
		{
			break;
		}
	}
	*counter = this_index - 1;
	return (width);
}
