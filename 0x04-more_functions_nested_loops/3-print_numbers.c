#include "main.h"
#include <stdio.h>
#define _CRT_SECURE_NO_WORNINGS

/**
 * print_number - print the number since 0 up to 9
 * Return: The numbers since 0 up to 9
 */

void print_numbers(void){
int x;
for (x = 0 ; x < 10 ; x+=1)
{
_putchar(x + '0');
}
_putchar('\n');

}
