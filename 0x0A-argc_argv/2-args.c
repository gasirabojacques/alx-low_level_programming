#include <stdio.h>

/**
 * main - prints all the arguments received
 * @argc: the number of arguments
 * @argv: an array of strings containing the arguments
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
int i;

for (i = 0; i < argc; i++)
{
printf("arg %d: %s\n", i, argv[i]);
}

return (0);
}
