#include "main.h"
#include <stdlib.h>
#include<string.h>
/**
 * *_realloc -  reallocates a memory block using malloc and free
 * @ptr: pointer
 * @old_size: size of allocated pointer
 * @new_size: new size
 * Return: pointer
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *new_ptr;
char *old_ptr;
unsigned int j;

if (new_size == old_size)
{
return (ptr);
}
if (new_size == 0 && ptr)
{
free(ptr);
return (NULL);
}
if (!ptr)
return (malloc(new_size));
new_ptr = malloc(new_size);
if (!new_ptr)
return (NULL);
old_ptr = ptr;
if (new_size < old_size)
{
for (j = 0; j < new_size; j++)
new_ptr[j] = old_ptr[j];
}
if (new_size > old_size)
{
for (j = 0; j < old_size; j++)
new_ptr[j] = old_ptr[j];
}
free(ptr);
return (new_ptr);
}
