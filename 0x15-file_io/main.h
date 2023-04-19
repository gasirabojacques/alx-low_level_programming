#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

ssize_t read_textfile(const char *filename, size_t letters);
size_t _strlen(char *str);
int create_file(const char *filename, char *text_content);
size_t _strlen(char *str);
int append_text_to_file(const char *filename, char *text_content);
