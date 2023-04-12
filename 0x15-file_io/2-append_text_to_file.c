#include <fcntl.h>
#include <unistd.h>
#include "main.h"
#include <stdio.h>
/**
 * append_text_to_file - Appends text to the end of a file.
 * @filename: A pointer to the name of the file.
 * @text_content: A pointer to the text content to append.
 *
 * Return: 1 on success, -1 on failure or if filename is NULL,
 * or if text_content is NULL and the file does not exist.
 */
int append_text_to_file(const char *filename, char *text_content)
{
int dir, text_len = 0, wrd;
if (filename == NULL)
return (-1);

if (text_content != NULL)
{
for (text_len = 0; text_content[text_len];)
text_len++;
}

dir = open(filename, O_WRONLY | O_APPEND);
if (dir == -1)
return (-1);

wrd = write(dir, text_content, text_len);
if (wrd == -1)
{
close(dir);
return (-1);
}
close(dir);
return (1);
}
