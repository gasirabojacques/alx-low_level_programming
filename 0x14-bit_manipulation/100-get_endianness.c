#include "main.h"
/**
 * get_endianness - checks the endianness
 *
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
int index;
char *c;

index = 1;
c = (char *)&index;

return (*c);
}
