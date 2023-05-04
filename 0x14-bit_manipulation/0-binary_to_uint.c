#include "main.h"

/**
 * binary_to_uint -converts a binary number to an unsigned int.
 * @bin: pointing to a string of 0 and 1 chars
 *
 * Return:converted number, or 0
 */
unsigned int binary_to_uint(const char *bin)
{
int index;
unsigned int k;

k = 0;
if (!bin)
return (0);
for (index = 0; bin[index] != '\0'; index++)
{
if (bin[index] != '0' && bin[index] != '1')
return (0);
}
for (index = 0; bin[index] != '\0'; index++)
{
k <<= 1;
if (bin[index] == '1')
k += 1;
}
return (k);
}
