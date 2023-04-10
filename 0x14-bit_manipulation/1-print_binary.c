#include "main.h"
#include "stdio.h"
/**
 * _power - calculates the power of a base to the exponent
 * @base: the base
 * @pow: the exponent
 *
 * Return: the result of the base raised to the exponent
 */

unsigned long int _power(unsigned int base, unsigned int pow)
{
unsigned long int num = 1;
unsigned int i;
for (i = 0; i < pow; i++)
{
unsigned long int temp = num;
unsigned int j;
for (j = 1; j < base; j++)
num += temp;
}
return (num);
}

int _putchar(char c);
void print_binary(unsigned long int n)
{
unsigned int driver;
unsigned long int gk = 1UL << (sizeof(unsigned long int) * 8 - 1);
for (driver = 0; driver < sizeof(unsigned long int) * 8; driver++)
{
if (n & gk)
{
_putchar('1');
}
else
{
_putchar('0');
}
gk >>= 1;
}
}
