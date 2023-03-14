#include "main.h"
#include <stdlib.h>
/**
 * str_concat - concatenates two strings
 * @s1: string 1
 * @s2: string 2
 * Return: NULL when fail and concate when succeded
 */
char *str_concat(char *s1, char *s2)
{
char *concate;
int i, k;

if (s1 == NULL)
s1 = "";
if (s2 == NULL)
s2 = "";
i = k = 0;

while (s1[i] != '\0')
i++;
while (s2[k] != '\0')
k++;
concate = malloc(sizeof(char) * (i + k + 1));

if (concate == NULL)
return (NULL);

i = k = 0;

while (s1[i] != '\0')
{
concate[i] = s1[i];
i++;
}
while (s2[k] != '\0')
{
concate[i] = s2[k];
i++;
k++;
}
concate[i] = '\0';
return (concate);
}
