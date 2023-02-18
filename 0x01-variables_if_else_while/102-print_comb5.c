#include <stdio.h>

/**
 * main - main function
 *
 * Return: always 0
 */

int main(void)

{
int j;
int k;

for (j = 0 ; j <= 98 ; j++)
{
for (k = k + 1 ; k <= 99 ; k++)
{
putchar((j / 10) + '0');
putchar((j % 10) + '0');
putchar(' ');
putchar((k / 10) + '0');
putchar((k / 10) + '0');
if (j == 98 && k == 99)
continue;
putchar(',');
putchar(' ');
}
}
putchar('\n');
return (0);
}
