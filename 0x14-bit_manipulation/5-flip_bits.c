#include "main.h"

/**
 * flip_bits - returns the number of bits you need to slip to get from one
 * number to another.
 * @n: original number - to slip
 * @m: target number - number to get to
 * Return: the number of bits to slip
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
unsigned long int check, dif, size;
unsigned int index, count = 0;

check = 1;
dif = n ^ m;
size = (sizeof(unsigned long int) * 8);

for (index = 0; index < size; index++)
{
if (check == (dif & check))
count++;
check <<= 1;
}

return (count);

}
