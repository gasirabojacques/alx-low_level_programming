#include "main.h"
/**
 * get_bit - Get the value of a specific bit in an unsigned long int.
 * @n: The unsigned long int to retrieve the bit from.
 * @index: The index of the bit to retrieve.
 *
 * Return: The value of the specified bit (0 or 1)
 * if successful, -1 if index is out of range.
 */
int get_bit(unsigned long int n, unsigned int index)
{
unsigned int mygeek = 1 << index;

if (index > (sizeof(unsigned long int) * 8 - 1))
return (-1);
if (n & mygeek)
return (1);
else
return (0);
}

