#include <stdio.h>
#include <ctype.h>
#include "main.h"
void print_buffer(char *b, int size)
{
int i, j;
for (i = 0; i < size; i += 10)
{
printf("%08x:", i);
for (j = i; j < i + 10; j += 2)
{
if (j < size)
{
printf(" %02x%02x", (unsigned char)b[j], (unsigned char)b[j + 1]);
}
else
{
printf("   ");
}
}
printf(" ");
for (j = i; j < i + 10; j++)
{
if (j < size)
{
printf("%c", isprint(b[j]) ? b[j] : '.');
}
else
{
printf(" ");
}
}
printf("\n");
}
if (size <= 0)
{
printf("\n");
}
}
