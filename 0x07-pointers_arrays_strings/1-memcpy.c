#include <stdio.h>

/**
 * simple_print_buffer - prints buffer in hexa
 * @buffer: the address of money to print
 * @size: the size of the memory to print
 *
 * Return: Nothing
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
char *p = dest;
while (n--)
{
*p++ = *src++;
}
return (dest);
}
int main(void)
{
char src[] = "Hello, world!";
char dest[20];
_memcpy(dest, src, sizeof(src));
printf("%s\n", dest);
return (0);
}
