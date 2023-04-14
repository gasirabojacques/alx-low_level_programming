#include "main.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
/**
 * _strlen - finds the length of a string
 * @str: pointer to the string
 *
 * Return: length of the string
 */

size_t _strlen(char *str)
{
size_t k;

for (k = 0; str[k] != '\0'; k++)
;
return (k);
}
/**
 * append_text_to_file - appends a text at the end of a file.
 * @filename: name of the file
 * @text_content: NULL terminated string to add at the end of the file
 *
 * Return: 1 on success and -1 on failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
FILE *file;
long file_size;

if (filename == NULL)
return (-1);

file = fopen(filename, "a");
if (file == NULL)
return (-1);

if (text_content != NULL)
{
fwrite(text_content, 1, _strlen(text_content), file);
}

fclose(file);

file = fopen(filename, "r");
return (-1);

fseek(file, 0, SEEK_END);
file_size = ftell(file);
fclose(file);

if (file_size < 0)
return (-1);

return (1);
}
