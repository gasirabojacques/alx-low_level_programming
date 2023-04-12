#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdarg.h>

#define size 1024

/**
 * print_error_and_exit - Prints an error message
 * to stderr and exits with the specified exit code.
 * @exit_code: The exit code to use when exiting the program.
 * @format: The format string for the error message.
 * @...: Additional arguments for the format string.
 */

void print_error_and_exit(int exit_code, const char *format, ...)
{
va_list args;
va_start(args, format);
dprintf(STDERR_FILENO, "Error: ");
vdprintf(STDERR_FILENO, format, args);
va_end(args);
exit(exit_code);
}
/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: 0 on success, or the appropriate exit code on failure.
 */
int main(int argc, char *argv[])
{
int dir_source, dir_destination;
ssize_t bytesRead, bytesWritten;
char buffer[size];
if (argc != 3)
{
print_error_and_exit(97, "Usage: %s file_from file_to\n", argv[0]);
}
dir_source = open(argv[1], O_RDONLY);
if (dir_source == -1)
{
print_error_and_exit(98, "Error: Can't read from file %s\n", argv[1]);
}
dir_destination = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC,
S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
if (dir_destination == -1)
{
print_error_and_exit(99, "Error: Can't write to file %s\n", argv[2]);
}
while ((bytesRead = read(dir_source, buffer, size)) > 0)
{
bytesWritten = write(dir_destination, buffer, bytesRead);
if (bytesWritten != bytesRead)
print_error_and_exit(99, "Error: Can't write to file %s\n", argv[2]);
}
if (bytesRead == -1)
{
print_error_and_exit(98, "Error: Can't read from file %s\n", argv[1]);
}
if (close(dir_source) == -1 || close(dir_destination) == -1)
{
print_error_and_exit(100, "Error: Can't close file descriptor\n");
}

return (0);
}
