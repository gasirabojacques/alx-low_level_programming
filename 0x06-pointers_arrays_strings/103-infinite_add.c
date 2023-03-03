#include <string.h>

/**
 * infinite_add - adds two numbers
 * @n1: first number to add
 * @n2: second number to add
 * @r: buffer to store result
 * @size_r: size of buffer
 *
 * Return: pointer to result, or 0 if buffer is too small to store result
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
 int len1 = strlen(n1);
 int len2 = strlen(n2);
 int carry = 0;
 int i, j;
for (i = 0, j = len1 - 1; i < j; ++i, --j)
{
char temp = n1[i];
n1[i] = n1[j];
n1[j] = temp;
}
for (i = 0, j = len2 - 1; i < j; ++i, --j)
{
char temp = n2[i];
n2[i] = n2[j];
n2[j] = temp;
}
for (i = 0; i < len1 || i < len2; ++i)
{
int digit1 = i < len1 ? n1[i] - '0' : 0;
int digit2 = i < len2 ? n2[i] - '0' : 0;
int sum = digit1 + digit2 + carry;
int digit = sum % 10;
carry = sum / 10;
if (i < size_r - 1)
{
r[i] = digit + '0';
}
else if (digit != 0 || carry != 0)
{
return 0;
}
}
if (carry != 0)
{
if (i < size_r - 1)
{
r[i] = carry + '0';
r[i + 1] = '\0';
}
else
{
return 0;
}
}
else
{
r[i] = '\0';
for (i = 0, j = strlen(r) - 1; i < j; ++i, --j)
{
char temp = r[i];
r[i] = r[j];
r[j] = temp;
}
}
return r;
}

