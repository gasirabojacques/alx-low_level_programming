#include "main.h"
int get_endianness(void)
{
int number = 1;
char *byte = (char *)&number;
if (byte[0] == 1)
{
return (1);
}
else
{
return (0);
}
}
