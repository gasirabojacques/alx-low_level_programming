#include "main.h"
#include <stdlib.h>
/**
 * *malloc_checked - allocates memory using malloc
 * @b: specify the number of bytes to be allocated
 * Return: to pointer and 98 if fails
 */

void *malloc_checked(unsigned int b)
{
void *c;

c = malloc(b);

if (c == NULL)
{
exit(98);
}
return (c);
}
