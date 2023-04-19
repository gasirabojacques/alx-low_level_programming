#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>

/**
 * read_textfile - Reads a text file and prints it to POSIX stdout.
 * @filename: A pointer to the name of the file.
 * @letters: The number of letters the
 * function should read and print.
 *
 * Return: If the function fails or filename is NULL - 0.
 * O/w - the actual number of bytes the function can read and print.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
ssize_t k, z, d;
char *buffer;

if (filename == NULL)
return (0);

buffer = malloc(sizeof(char) * letters);
if (buffer == NULL)
return (0);

k = open(filename, O_RDONLY);
z = read(k, buffer, letters);
d = write(STDOUT_FILENO, buffer, z);

if (k == -1 || z == -1 || d == -1 || d != z)
{
free(buffer);
return (0);
}

free(buffer);
close(z);

return (d);
}
