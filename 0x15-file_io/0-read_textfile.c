#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>


/**
 * read_textfile - reads a text file and prints the letters
 * @filename: filename.
 * @letters: numbers of letters printed.
 *
 * Return: numbers of letters printed. It fails, returns 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
int dir;
ssize_t d, r;
char *buf;

if (!filename)
return (0);

dir = open(filename, O_RDONLY);

if (dir == -1)
return (0);

buf = malloc(sizeof(char) * (letters));
if (!buf)
return (0);

d = read(dir, buf, letters);
r = write(STDOUT_FILENO, buf, d);

close(dir);

free(buf);

return (r);
}
