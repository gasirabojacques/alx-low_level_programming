#include "main.h"

/**
 * _strcmp - comapre string
 * @s1: strings
 * @s2: strings
 * Return: 0
 */

int _strcmp(char *s1, char *s2)
{
int i;

for (i = 0 ; s1[i] != '\0' ||  s2[i] != '\0' ; i++)
{
if (s1[i] != s2[i])
{
if (s1[i] < s2[i])
return (s1[i] - s2[i]);
else if (s1[i] > s2[i])
return (s1[i] != s2[i]);
}
else
return (0);
}
return (0);
}
