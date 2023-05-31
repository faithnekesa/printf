#include "main.h"
/**
* getFlags -A function that gets active flags
* @format:String formatted to print arguments
* @counter: take a parameter.
* Return: Flags:
*/
int getFlags(const char *format, int *counter)
{
int next_index, this_index;
int inputFlags = 0;
const char FLAGS_CH_[] = {'-', '+', '0', '#', ' ', '\0'};
const int FLAGS_ARR_[] = {F_MINUS_, F_PLUS_, F_ZERO_, F_HASH_,
F_SPACE_, 0};
for (this_index = *counter + 1; format[this_index] != '\0'; this_index++)
{
for (next_index = 0; FLAGS_CH_[next_index] != '\0'; next_index++)
if (format[this_index] == FLAGS_CH_[next_index])
{
inputFlags |= FLAGS_ARR_[next_index];
break;
}
if (FLAGS_CH_[next_index] == 0)
break;
}
*counter = this_index - 1;
return (inputFlags);
}
