#include "main.h"
#include <stdio.h>
int _putchar(char c);

/**
 * Print_number - Prints an integer
 * @n: The integer to prints
 * Return: Nothing
 */

void print_number(int n)
{
int divisor = 1;
if (n < 0)
{
_putchar('-');
n *= -1;
}
while (n / divisor >= 10)
{
divisor *= 10;
}
while (divisor != 0)
{
_putchar((n / divisor)+'0');
n %= divisor;
divisor /= 10;
}
}
