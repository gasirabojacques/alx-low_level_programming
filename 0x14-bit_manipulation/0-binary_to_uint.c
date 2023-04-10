#include "main.h"
#include <stddef.h>
#include <stdio.h>


/**
 * Binary_to_uint -convert a binary number to an unsigned int.
 * @b: pointing to a string of 0 and 1 chars
 * Return: 0
 */

unsigned int binary_to_uint(const char *b)
{
int j;
unsigned int result = 0;


if (b == NULL)
{
return (0);
}

for (j = 0; b[j] != '\0' ; j++)
{
if (b[j] != '0' && b[j] != '1')
{
return (0);
}
}

for (j = 0; b[j] != '\0'; j++)
{
result <<= 1;
if (b[j] == '1')
{
result += 1;
}
}
return (j);
}

int main(void)
{
const char *b = "10101010";
unsigned int result = binary_to_uint(b);


printf("Binary string %s is equal to unsigned integer %u \n", b, result);

return (0);
}
