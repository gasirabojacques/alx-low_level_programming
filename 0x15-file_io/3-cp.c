#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * error_file - checks if files can be opened.
 * @file_from: file_from.
 * @file_to: file_to.
 * @argv: arguments vector.
 * Return: no return.
 */
void error_file(int file_source, int file_destin, char *argv[])
{
if (file_source == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
exit(98);
}
if (file_destin == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
exit(99);
}
}

/**
 * main - check the code for Holberton School students.
 * @argc: number of arguments.
 * @argv: arguments vector.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
int file_source, file_destin, err_close;
ssize_t nchars, r;
char buf[1024];

if (argc != 3)
{
dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
exit(97);
}

file_source = open(argv[1], O_RDONLY);
file_destin = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
error_file(file_source, file_destin, argv);

nchars = 1024;
while (nchars == 1024)
{
nchars = read(file_source, buf, 1024);
if (nchars == -1)
error_file(-1, 0, argv);
r = write(file_destin, buf, nchars);
if (r == -1)
error_file(0, -1, argv);
}

err_close = close(file_source);
if (err_close == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_source);
exit(100);
}

err_close = close(file_destin);
if (err_close == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_source);
exit(100);
}
return (0);
}
