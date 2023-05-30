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
/**
 * printInteger -Function to print an integer
 * @list: Argument list
 * @buffer: A buffer array to handle print function
 * @size: Size specifier
 * @precision_param: Precision specified
 * Return: The number of chars printed
 */

int printInteger(va_list list, char buffer[], int precision_param, int size)
{
	int buffsize = BUFF_SIZE - 2;
	int is_negative = 0;
	long int numL = va_arg(list, long int);
	unsigned long int numU;
	
	numL = convert_size_number(numL, size);
	if (numL == 0)
	buffer[buffsize--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	numU = (unsigned long int)numL;
	if (numL < 0)
		{
			numU = (unsigned long int)((-1) * numL);
			is_negative = 1;
		}
	while (numU > 0)
	{
		buffer[buffsize--] = (numU % 10) + '0';
		numU = numU / 10;
	}
	buffsize++;
	return (write_number(is_negative, buffsize, buffer, precision_param, size));
}

/**
 * printBinary - Prints an unsigned number
 * @list: Lista of arguments
 * @buffer: Buffer array to handle print
 * @precision_param: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */

int printBinary(va_list list, char buffer[], int precision_param, int size)
{
        unsigned int num1, num2, index, summation;
        unsigned int numU[32];
        int count;
	UNUSED(buffer);
	UNUSED(precision_param);
	UNUSED(size);

	num1 = va_arg(list, unsigned int);
	num2 = 2147483648; /* (2 ^ 31) */
	numU[0] = num1 / num2;
	for (index = 1; index < 32; index++)
	{
		num2 =num2 / 2;
		numU[index] = (num1 / num2) % 2;
	}
	for (index = 0, summation = 0, count = 0; index < 32; index++)
	{
		summation += numU[index];
		if (summation || index == 31)
		{
			char charnum = '0' + numU[index];

			write(1, &charnum, 1);
			count++;
		}
	}
	return (count);
}
