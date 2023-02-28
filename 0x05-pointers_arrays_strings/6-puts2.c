#include "main.h"
int _putchar(char c);
/**
 * puts2 - prints every other character of a string
 * @str: The string to be treated
 */

void puts2(char *str)

{
int i;
int j = 0;

while (str[j] != '\0')
{
j++;
}

for (i = 0 ; i < j ; i += 2)
{
_putchar(str[i]);
}
_putchar('\n');
}
