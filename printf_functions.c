#include "main.h"

/**
* print_char - Function that prints a character
* @list: List a of arguments
* @buffer: the buffer for array to handle printing
* @flags: checks for active flags
* @width: Width
* @precision: Precision specification
* @size: the size of the specifier
* Return: the num of chars printed
*/
int print_char(va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(list, int);

	return (handleWriteChar(c, buffer, flags, width, precision, size));
}

/**
* print_string -Function that prints a stringPtring
* @list:argument list
* @buffer: the buffer for array to handle printing
* @flags: checks for active flags
* @width: get width.
* @precision: Precision specifier
* @size: Size of the specifier
* Return: The number of chars printed
*/
int print_string(va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, counter;
	char *stringPtr = va_arg(list, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (stringPtr == NULL)
	{
		stringPtr = "(null)";
		if (precision >= 6)
			stringPtr = "      ";
	}

	while (stringPtr[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS_)
		{
			write(1, &stringPtr[0], length);
			for (counter = width - length; counter > 0; counter--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (counter = width - length; counter > 0; counter--)
				write(1, " ", 1);
			write(1, &stringPtr[0], length);
			return (width);
		}
	}

	return (write(1, stringPtr, length));
}

/**
* print_percent -Function that prints %
* @list:argument list
* @buffer: the buffer for array to handle printing
* @flags: checks for active flags
* @width: get width.
* @precision: Precision specifier
* @size: Size of the specifier
* Return: The number of chars printed
*/
int print_percent(va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(list);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}


/**
* print_int - Print int
* @list:argument list
* @buffer: the buffer for array to handle printing
* @flags: checks for active flags
* @width: get width.
* @precision: Precision specifier
* @size: Size of the specifier
* Return: The number of chars printed
*/
int print_int(va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int counter = BUFF_SIZE - 2;
	int is_negative = 0;
	long int num1 = va_arg(list, long int);
	unsigned long int num;

	if (num1 == 0)
		buffer[counter--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)num1;

	if (num1 < 0)
	{
		num = (unsigned long int)((-1) * num1);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[counter--] = (num % 10) + '0';
		num /= 10;
	}

	counter++;

	return (write_number(is_negative, counter, buffer, flags,
				width, precision, size));
}

/**
* print_binary - Prints an unsigned number
* @list:argument list
* @buffer: the buffer for array to handle printing
* @flags: checks for active flags
* @width: get width.
* @precision: Precision specifier
* @size: Size of the specifier
* Return: The number of chars printed
*/
int print_binary(va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int num1, num2, counter, sum;
	unsigned int num3[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	num1 = va_arg(list, unsigned int);
	num2 = 2147483648; /* (2 ^ 31) */
	num3[0] = num1 / num2;
	for (counter = 1; counter < 32; counter++)
	{
		num2 /= 2;
		num3[counter] = (num1 / num2) % 2;
	}
	for (counter = 0, sum = 0, count = 0; counter < 32; counter++)
	{
		sum += num3[counter];
		if (sum || counter == 31)
		{
			char newChar = '0' + num3[counter];

			write(1, &newChar, 1);
			count++;
		}
	}
	return (count);
}

