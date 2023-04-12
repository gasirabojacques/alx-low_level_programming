#include <stdio.h>
#include <stdlib.h>
/**
 * read_textfile - Reads a text file and prints it to standard output.
 * @filename: A pointer to the name of the file.
 * @letters: The number of letters the function should read and print.
 *
 * Return: If the function fails or filename is NULL - 0.
 *         O/w - the actual number of bytes the function can read and print.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
FILE *file = fopen(filename, "r");
char *buffer = (char *) malloc(letters + 1);
size_t bytesRead;
if (filename == NULL)
{
return (0);
}
if (file == NULL)
{
return (0);
}
if (buffer == NULL)
{
fclose(file);
return (0);
}
bytesRead = fread(buffer, 1, letters, file);
buffer[bytesRead] = '\0';
fwrite(buffer, 1, bytesRead, stdout);
fclose(file);
free(buffer);
return (bytesRead);
}
