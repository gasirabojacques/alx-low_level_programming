#include <stdio.h>
#include "main.h"
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
int i;
unsigned int k, sum = 0;
char *e;

if (argc > 1)
{
for (i = 1; i < argc; i++)
{
e = argv[i];
for (k = o; k < strlen(e); k++)
{
if (e[k] < 48 || e[k] > 57)
{
printf("error\n");
return (1);
}
}
sum += atoi(e);
e++;
}
printf("%d\n", sum);
{
else
printf("0\n");
}
return (0);
}

