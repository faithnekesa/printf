/**
 * printChar -Function to print char
 * @list: Argument list
 * @precision_param: Precision specification
 * Return: The number of chars printed
 */
int printChar(va_list list, int precision_param)
{
	char c = va_arg(list, int);

	return (print_op(c, precision_param));
}

/**
 * printString -Function to print a string
 * @list: List a of arguments
 * @precision_param: Precision specification
 * Return:The number of chars printed
 */
int printString(va_list list, int precision_param)
{
	int Strnlength = 0;
	char *string_ptr = va_arg(list, char *);
	UNUSED(precision_param);
	if (string_ptr == NULL)
	{
		string_ptr = "(null)";
		if (precision_param >= 6)
			string_ptr = " ";
	}

	while (string_ptr[Strnlength] != '\0')
		Strnlength++;

	if (precision_param >= 0 && precision_param < Strnlength)
		Strnlength = precision_param;
return (write(1, string_ptr, Strnlength));
}

/**
 * printPercent -Function to print %
 * @list: Argument list
 * @precision_param: Precision specification
 * Return: The number of chars printed
 */

int printPercent(va_list list,int precision_param)
{
	UNUSED(list);
	UNUSED(precision_param);
	return (write(1, "%%", 1));
}
