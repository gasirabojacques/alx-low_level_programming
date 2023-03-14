#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * argstostr -  concatenates all the arguments of your program
 * @ac: number of arguments
 * @av: pointer to  array
 * Return: null if ac or av is 0 and string otherwise
 */

char *argstostr(int ac, char **av)
{
int p;
int k;
int length;
char *str;

length = 0;
p = 0;

if (ac == 0 || av == 0)
{
return (NULL);
}

for (k = 0; k < ac; k++)
{
length += strlen(av[k]) + 1;
}
str = malloc(1 + length *sizeof(char));
if (str == 0)
{
return (NULL);
}
for (k = 0; k < ac; k++)
{
strcpy(str + p, av[k]);
p += strlen(av[k]);
str[p++] = '\n';
}
str[p] = '\0';
return (str);
}
