#include "main.h"
#include <stdlib.h>

/**
 * **alloc_grid -  returns a pointer to a 2 dimensional array of integers
 * @width: dimension
 * @height: dimension
 * Return: NULL if dimensions are 0 or - and dimensions otherwise
 */

int **alloc_grid(int width, int height)
{
int **grid;
int k;
int i;

if (width <= 0 || height <= 0)
{
return (NULL);
}
grid = malloc(height * sizeof(int *));
if (grid == NULL)
{
return (NULL);
}
for (i = 0; i < height; i++)
{
grid[i] = malloc(width * sizeof(int));
if (grid[i] == NULL)
{
for (; i >= 0; i--)
{
free(grid[i]);
}
free(grid);
return (NULL);
}
}
for (i = 0; i < height; i++)
{
for (k = 0; k < width; k++)
{
grid[i][k] = 0;
}
}
return (grid);
}
