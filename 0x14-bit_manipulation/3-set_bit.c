#include "main.h"
/**
 * set_bit - Set a specific bit in an unsigned long int.
 * @n: Pointer to the unsigned long int to set the bit in.
 * @index: The index of the bit to set.
 *
 * Return: 1 on success, -1 on error.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
unsigned long int mygeek = 1UL << index;
if (index > (sizeof(unsigned long int) * 8 - 1))
{
return (-1);
}
*n = *n | mygeek;
return (1);
}
