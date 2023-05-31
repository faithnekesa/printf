#include "main.h"

/**
 * isPrintable - Evaluates if a char is printable
 * @c: Char to be evaluated.
 *
 * Return: 1 if c is printable, 0 otherwise
 */

int isPrintable(char c)
{
	if (c >= 32 && c < 127)
	{
		return (1);
	}
	return (0);
}

/**
 * isDigit - Verifies if a char is a digit
 * @c: Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */

int isDigit(char c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}
