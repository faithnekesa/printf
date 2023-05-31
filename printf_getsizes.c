#include "main.h"

/**
 * getSize - Gets argument size
 * @format: The formatted string to print arguments
 * @argList: Argument list to be printed
 *
 * Return: the precision arguments
 */

int getSize(const char *format, int *argList)
{
	int this_index = *argList + 1;
	int count = 0;

	if (format[this_index] == 'l')
	{
		count = S_LONG_;
	}
	else if (format[this_index] == 'h')
	{
		count = S_SHORT_;
	}
	if (count == 0)
	{
		*argList = this_index - 1;
	}
	else
	{
		*argList = this_index;
	}
	return (count);
}
