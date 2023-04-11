#include <stdio.h>
#include <string.h>
int create_file(const char *filename, char *text_content)
{
FILE *file;
if (filename == NULL)
{
printf("Error: filename is NULL\n");
return (-1);
}
file = fopen(filename, "w");
if (file == NULL)
{
printf("Error: File to create file\n");
return (-1);
}
if (text_content != NULL)
{
size_t text_len = strlen(text_content);
fwrite(text_content, sizeof(char), text_len, file);
}
fclose(file);
return (1);
}
