#include "main.h"
#include <stdlib.h>

/**
 * *array_range - creates an array of integers
 * @min: minimum value
 * @max: maximum value
 * Return: pointer
 */

int *array_range(int min, int max)
{
int *ary;
int p, size;

if (min > max)
{
return (NULL);
}
size = max - min + 1;
ary = malloc(sizeof(int) * size);

if (ary == NULL)
{
return (NULL);
}
for (p = 0; p < size; p++)
{
ary[p] = min + p;
}
return (ary);
}
