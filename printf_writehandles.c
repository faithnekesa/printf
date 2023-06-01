#include "main.h"
/**
* handleWriteChar - Function to prints a string
* @buffer: Buffer array to handle print
* @flags:Checks for active flags.
* @width:Function to get width
* @c: character passed
* @precision: precision specifier
* @size: Size of thespecifier
* Return: Number of chars printed
**/

int handleWriteChar(char c, char buffer[],
int flags, int width, int precision, int size)
{
int counter = 0;
char padding_char = ' ';
UNUSED(precision);
UNUSED(size);
if (flags & F_ZERO_)
padding_char = '0';
buffer[counter++] = c;
buffer[counter] = '\0';
if (width > 1)
{
buffer[BUFF_SIZE - 1] = '\0';
for (counter = 0; counter < width - 1; counter++)
buffer[BUFF_SIZE - counter - 2] = padding_char;
if (flags & F_MINUS_)
return (write(1, &buffer[0], 1) +
write(1, &buffer[BUFF_SIZE - counter - 1], width - 1));
else
return (write(1, &buffer[BUFF_SIZE - counter - 1], width - 1) +
write(1, &buffer[0], 1));
}
return (write(1, &buffer[0], 1));
}

/**
* write_number- Check if a num is negative and prints it
* @is_negative:Argument list
* @index: type of char
* @buffer:The buffer array that handles print
* @flags:checks for active flags
* @width:Function that gets width
* @precision: precision specifier
* @size: Size of specifier
* Return:the number of chars printed
*/
int write_number(int is_negative, int index, char buffer[],
int flags, int width, int precision, int size)
{
int length = BUFF_SIZE - index - 1;
char padding_char = ' ';
char additional_char = 0;
UNUSED(size);
if ((flags & F_ZERO_) && !(flags & F_MINUS_))
padding_char = '0';
if (is_negative)
additional_char = '-';
else if (flags & F_PLUS_)
additional_char = '+';
else if (flags & F_SPACE_)
additional_char = ' ';
return (write_num(index, buffer, flags, width, precision,
length, padding_char, additional_char));
}
/**
* write_num - Prints a num using bufffer
* @index: Initial index in the buffer
* @buffer:The buffer
* @flags:the flags
* @width:the width
* @prec_arg: the precision specifier
* @length:the length
* @padding_char:The padding chara
* @additional_char: Additional char
* Return:The number of printed chars
*/

int write_num(int index, char buffer[],
	int flags, int width, int prec_arg,
	int length, char padding_char, char additional_char)
{
	int counter, padd_start = 1;

	if (prec == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0' && width == 0)
		return (0);
	if (prec == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
		buffer[index] = padding_char = ' ';
	if (prec > 0 && prec < length)
		padding_char = ' ';
	while (prec > length)
		buffer[--index] = '0', length++;
	if (additional_char != 0)
		length++;
	if (width > length)
	{
		for (counter = 1; counter < width - length + 1; counter++)
			buffer[counter] = padding_char;
		buffer[counter] = '\0';
		if (flags & F_MINUS_ && padding_char == ' ')
		{
			if (additional_char)
				buffer[--index] = additional_char;
			return (write(1, &buffer[index], length) +
					write(1, &buffer[1], counter - 1));
		}
		else if (!(flags & F_MINUS_) && padding_char == ' ')
		{
			if (additional_char)
				buffer[--index] = additional_char;
			return (write(1, &buffer[1], counter - 1) +
					write(1, &buffer[index], length));
		}
		else if (!(flags & F_MINUS_) && padding_char == '0')
		{
			if (additional_char)
				buffer[--padd_start] = additional_char;
			return (write(1, &buffer[padd_start], counter - padd_start) +
				write(1, &buffer[index], length - (1 - padd_start)));
		}
	}
	return (write(1, &buffer[index], length));
}
