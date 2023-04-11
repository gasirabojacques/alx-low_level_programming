#include <stdio.h>
#include <stdlib.h>
ssize_t read_textfile(const char *filename, size_t letters)
{
FILE *file = file = fopen(filename, "r");
char buffer[1024];
ssize_t letter_read = fread(buffer, sizeof(char), letters, file);
if (filename == NULL)
{
return (0);
}
if (file == NULL)
{
return (0);
}
if (letter_read <= 0)
{
fclose(file);
return (0);
}
fclose(file);
return (letter_read);
}
