#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char *_strncat(char *dest, char *src, int n)
{
strncat(dest, src, n);
return dest;
}
