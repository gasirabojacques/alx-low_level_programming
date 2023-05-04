#include "main.h"
#include <stdio.h>
/**
 * print_binary - prints the biinary representation of a number.
 * @n: number to represent in binary
 */

void print_binary(unsigned long int n)
{
int counter, k;
int flag = 0;

if (n == 0)
{
putchar('0');
return;
}

for (counter = 63; counter >= 0; counter--)
{
k = n >> counter;
if (k & 1)
{
flag = 1;
putchar('1');
}
else if (flag == 1)
putchar('0');
}
}
