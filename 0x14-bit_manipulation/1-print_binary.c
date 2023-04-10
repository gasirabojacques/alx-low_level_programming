#include "main.h"
#include "stdio.h"
/**
 * _power - calcurate the of a number.
 * @base: base of the exponet
 * @pow power of the exponet
 * return: Result of base raised to the power of pow.
 **/
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
