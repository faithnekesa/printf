#include "main.h"

/**
 * _printf -A function that works like printf
 * @format:Pointer to strings containing the specifiers
 * Return:output to stdout, and  the number of characters printed
 * * excluding the null byte used to end output to strings
 */

int _printf(const char *format, ...)
{
	int printedArgs = 0, counter, charsPrinted = 0;
	int flags, width, precisionParams, size, buffer_index = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (counter = 0; format && format[counter] != '\0'; counter++)
	{
		if (format[counter] != '%')
		{
			buffer[buffer_index++] = format[counter];
			if (buffer_index == BUFF_SIZE)
				printBuffer(buffer, &buffer_index);
			charsPrinted++;
		}
		else
		{
			printBuffer(buffer, &buffer_index);
			flags = get_flags(format, &counter);
			width = get_width(format, &counter, list);
			precisionParams = get_precision(format, &counter, list);
			size = get_size(format, &counter);
			++counter;
			printedArgs = handle_print(format, &counter, list, buffer,
				flags, width, precisionParams, size);
			if (printedArgs == -1)
				return (-1);
			charsPrinted += printedArgs;
		}
	}

	printBuffer(buffer, &buffer_index);

	va_end(list);

	return (charsPrinted);
}

/**
 * printBuffer -Function that prints the buffer content if exists
 * @buffer: The array of characters
 * @buffer_index: Represents the length
 */
void printBuffer(char buffer[], int *buffer_index)
{
	if (*buffer_index > 0)
		write(1, &buffer[0], *buffer_index);

	*buffer_index = 0;
}
