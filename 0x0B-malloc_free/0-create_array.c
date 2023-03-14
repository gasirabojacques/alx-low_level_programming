#include "main.h"
#include <stdlib.h>
/**
 * create_array - creates an array of chars,
 * and initializes it with a specific char
 * @size: size of an array
 * @c: character for initialization
 * Return: NULL id soze is equal to 0 or fails,
 * and to the pointer
 */

char *create_array(unsigned int size, char c)
{
unsigned int k;
char *ary;

if (size == 0)
{
return (NULL);
}
ary = malloc(size * sizeof(char));
if (ary == 0)
{
return (NULL);
}
for (k = 0; k < size; k++)
{
ary[k] = c;
}
return (ary);
}
