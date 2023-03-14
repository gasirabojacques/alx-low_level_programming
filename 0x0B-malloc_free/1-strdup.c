#include "main.h"
#include <string.h>
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter
 * @str: pointer to string to be copied
 * Return: NULL if str is 0 and new allocation if successful
 */

char *_strdup(char *str)
{
int length;
char *copy;

if (str == 0)
{
return (NULL);
}

length = strlen(str);
copy = malloc((length + 1) * sizeof(char));

if (copy == 0)
{
return (NULL);
}
strcpy(copy, str);
return (copy);
}
