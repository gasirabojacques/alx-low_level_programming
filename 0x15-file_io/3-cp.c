#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
/**
 * check97 - checks for the correct number of arguments
 * @argc: number of arguments
 *
 * Return: void
 */
void check97(int argc)
{
if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}
}

/**
 * check98 - checks that file_from exists and can be read
 * @check: checks if true of false
 * @file: file_from name
 * @fd_from: file descriptor of file_from, or -1
 * @fd_to: file descriptor of file_to, or -1
 *
 * Return: void
 */
void check98(ssize_t check, char *file, int dir_source, int dir_destin)
{
if (check == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
if (dir_source != -1)
close(dir_source);
if (dir_destin != -1)
close(dir_destin);
exit(98);
}
}

/**
 * check99 - checks that file_to was created and/or can be written to
 * @check: checks if true of false
 * @file: file_to name
 * @fd_from: file descriptor of file_from, or -1
 * @fd_to: file descriptor of file_to, or -1
 *
 * Return: void
 */
void check99(ssize_t check, char *file, int dir_source, int dir_destin)
{
if (check == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
if (dir_source != -1)
close(dir_source);
if (dir_destin != -1)
close(dir_destin);
exit(99);
}
}

/**
 * check100 - checks that file descriptors were closed properly
 * @check: checks if true or false
 * @fd: file descriptor
 *
 * Return: void
 */
void check100(int check, int dir)
{
if (check == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", dir);
exit(100);
}
}
/**
 * main - opies the content of a file to another file.
 * @argc: number of arguments passed
 * @argv: array of pointers to the arguments
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
int dir_source, dir_destin, close_source, close_destin;
ssize_t lenr, lenw;
char buffer[1024];
mode_t file_perm;

check97(argc);
dir_source = open(argv[1], O_RDONLY);
check98((ssize_t)dir_source, argv[1], -1, -1);
file_perm = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
dir_destin = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, file_perm);
check99((ssize_t)dir_destin, argv[2], dir_source, -1);
lenr = 1024;
while (lenr == 1024)
{
lenr = read(dir_source, buffer, 1024);
check98(lenr, argv[1], dir_source, dir_destin);
lenw = write(dir_destin, buffer, lenr);
if (lenw != lenr)
lenw = -1;
check99(lenw, argv[2], dir_source, dir_destin);
}
close_destin = close(dir_destin);
close_source = close(dir_source);
check100(close_destin, dir_destin);
check100(close_source, dir_source);
return (0);
}
