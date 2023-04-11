#include "main.h"
/**
 * clear_bit - Clear the value of a specific bit in an unsigned long int.
 * @n: The unsigned long int to clear the bit in.
 * @index: The index of the bit to clear.
 *
 * Return: 1 if successful, -1
 *if an error occurred (e.g., index is out of range).
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
unsigned long int mygeek = 1UL << index;

if (index > (sizeof(unsigned long int) * 8 - 1))
{
return (-1);
}
*n &= ~mygeek;
return (1);
}
