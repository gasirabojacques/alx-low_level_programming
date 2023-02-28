#include <stdio.h>
int _putchar(char c);
/**
 * puts_half - prints half of a string
 * @str: The string to print
 * Return: void
 */

void puts_half(char *str)

{
int j = 0;
int g;

while (str[j] != '\0')
{
j++;
}
if (j % 2 == 1)
{
g = ((j - 1) / 2);
g += 1;
}
else
{
g = j / 2;
}

for (; g < j ; g++)
{
_putchar(str[g]);
}
_putchar('\n');
}
