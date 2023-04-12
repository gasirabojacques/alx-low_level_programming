#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
/**
 * append_text_to_file - Appends text to the end of a file.
 * @filename: A pointer to the name of the file.
 * @text_content: A pointer to the text content to append.
 *
 * Return: 1 on success, -1 on failure or if filename is
 *NULL, or if text_content is NULL and the file does not exist.
 */
int append_text_to_file(const char *filename, char *text_content)
{
FILE *file = fopen(filename, "a");
size_t text_length;
if (filename == NULL)
{
return (-1);
}
if (file == NULL)
{
return (-1);
}
if (text_content != NULL)
{
text_length = strlen(text_content);
if (fwrite(text_content, 1, text_length, file) != text_length)
{
fclose(file);
return (-1);
}
}
fclose(file);
return (1);
}
