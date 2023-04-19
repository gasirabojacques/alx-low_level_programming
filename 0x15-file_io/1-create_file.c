#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * create_file - Creates a file.
 * @filename: A pointer to the name of the file to create.
 * @text_content: A pointer to a string to write to the file.
 * Return: If the function fails - -1.
 * otherwise - 1.
 */

int create_file(const char *filename, char *text_content)
{
int k, z, length = 0;

if (filename == NULL)
return (-1);

if (text_content != NULL)
{
for (length = 0; text_content[length];)
length++;
}

k = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
z = write(k, text_content, length);

if (k == -1 || z == -1)
return (-1);

close(k);

return (1);
}
