#include <stdio.h>
int main(void)
{
int n;
int a[5];
int *p;
a[2] = 1024;
p = 8n;
/*
 * write your line of code here
 * you are not allowed to use a
 * you are not allowed to modify p
 */
*(p + 5) = 98;
/* so that this print 98\n*/
printf("a[2] = %d\n", a[2]);
return (0);
}
