#include "main.h"
void printBuffer(char buffer[], int *buffer_index);
/**
* _printf - A function like printf function
* @format:Formatted string to print arguments
* Return:The number of chars printed
*/
int _printf(const char *format, ...)
{
int printedArgs = 0, counter = 0, charsPrinted = 0;
int precision, flags, width, size, buffer_index = 0;
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
flags = getFlags(format, &counter);
precision = get_precision(format, &counter, list);
width = get_width(format, &counter, list);
size = get_size(format, &counter);
++counter;
printedArgs = doPrint(format, &counter, list, buffer,
flags, width, precision, size);
if (printedArgs == -1)
return (-1);
charsPrinted = charsPrinted +  printedArgs;
}
}
printBuffer(buffer, &buffer_index);
va_end(list);
return (charsPrinted);
}

/**
* printBuffer - Prints the contents of the buffer if it exist
* @buffer: Array of chars
* @buffer_index: Index for the next arg- the length
*/
void printBuffer(char buffer[], int *buffer_index)
{
if (*buffer_index > 0)
write(1, &buffer[0], *buffer_index);
*buffer_index = 0;
}
