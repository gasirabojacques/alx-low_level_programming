#include "main.h"
int _putchar(char c);
/**
 * _print_rev_recursion - print a string in reverse
 * @s: tht string to reverse
 *
 * Return: Nothing
 */

void _print_rev_recursion(char *s)
{
if (*s == '\0')
{
return;
}
s++;
_print_rev_recursion(s);
s--;
_putchar(*s);
}
