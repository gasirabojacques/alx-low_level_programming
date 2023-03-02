#include "main.h"

/**
 * cap_string - capitalizes words
 * @str: string
 * Return: pointer to the modified string
 */

char *cap_string(char *str)
{
int i = 0;
while (str[i])
{
while (!(str[i] >= 'a' && str[i] <= 'z'))
i++;
if (i == 0 || str[i - 1] == ' ' ||
str[i - 1] == '\t' ||
str[i - 1] == '\n' ||
str[i - 1] == ',' ||
str[i - 1] == ';' ||
str[i - 1] == '.' ||
str[i - 1] == '!' ||
str[i - 1] == '?' ||
str[i - 1] == '"' ||
str[i - 1] == '(' ||
str[i - 1] == ')' ||
str[i - 1] == '{' ||
str[i - 1] == '}')
{
str[i] -= 32;
}
i++;
}
return (str);
}
