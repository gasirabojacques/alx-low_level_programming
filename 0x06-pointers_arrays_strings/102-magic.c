#include <stdio.h>
/*
* ou are not allowed to use the variable a in your new line of code
* You are not allowed to modify the variable p
* You can only write one statement
* You are not allowed to use ,
* Your code should be written at line 19, before the ;
* Do not remove anything from the initial code (not even the comments)
* You are allowed to use the standard library
*/
int main(void)
{
int a[] = { 1, 2, 98, 4, 5 };
int *p = a;
printf("a[2] = %d\n", *(p + 2));
return (0);
}
