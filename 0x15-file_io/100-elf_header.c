#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdint.h>
#include <string.h>

#define SIZE 16

/**
 * display_magic - Displays the magic numbers from the ELF header buffer.
 * @buffer: Buffer containing the ELF header.
 * @size: Size of the magic numbers in bytes.
 *
 * This function takes a buffer containing the ELF header and the size of the
 * magic numbers, and displays them in hexadecimal format. The size parameter
 * specifies the number of bytes to be displayed from the buffer.
 */



void display_magic(uint8_t *buffer, int size)
{
int i;
printf("Magic: ");
for (i = 0; i < size; i++)
{
printf("%02x ", buffer[i]);
}
printf("\n");
}

/**
 * display_class_version - Displays the class and
 * version information from the ELF header buffer.
 * @buffer: Buffer containing the ELF header.
 */


void display_class_version(uint8_t *buffer)
{
printf("Class: %s\n", buffer[4] == 1 ? "ELF32" :
buffer[4] == 2 ? "ELF64" : "Unknown");
printf("Version: %d (current)\n", buffer[6]);
printf("OS/ABI : %s\n", buffer[7] == 0 ? "UNIX - System V" :
buffer[7] == 1 ? "ABI Version: 1" : "Unknown");
}

/**
 * display_type - Displays the type of
 * the ELF file from the ELF header buffer.
 * @buffer: Buffer containing the ELF header.
 */


void display_type(uint8_t *buffer)
{
uint64_t entryPoint;
printf("Type :   ");
if (buffer[16] == 1)
{
printf("REL (Relocation file)\n");
}
else if (buffer[16] == 2)
{
printf("EXEC (Executable file)\n");
}
else if (buffer[16] == 3)
{
printf("DYN (shared object file)\n");
}
else
{
printf("Unknown\n");
}
memcpy(&entryPoint, &buffer[24], 8);
printf("Entry point address : 0x%lx\n", entryPoint);

}


/**
 * display_elf_header - Displays various information from the ELF header.
 * @dir: File descriptor of the ELF file.
 *
 * This function reads the ELF header from the file descriptor into a buffer,
 * and then calls other functions to display different information from the
 * ELF header, including the magic number, class and version, and type.
 * If the read operation fails or does not read the expected number of bytes,
 * an error message is printed to stderr and the program exits
 * with an error code of 98.
 */

void display_elf_header(int dir)
{
int size = 16;
uint8_t buffer[SIZE];
ssize_t bytesRead = read(dir, buffer, SIZE);
if (bytesRead != SIZE)
{
fprintf(stderr, "Error: Failed to read ELF header\n");
exit(98);
}

display_magic(buffer, size);
display_class_version(buffer);
display_type(buffer);
}

/**
 * main - Entry point. Validates command-line arguments, opens ELF file,
 * calls 'display_elf_header', and returns exit code.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 *
 * This function serves as the entry point of the program. It validates the
 * command-line arguments, opens the ELF file specified as an argument, calls
 * the 'display_elf_header' function to display the ELF header information,
 * and returns the exit code. If any error occurs, an appropriate error message
 * is printed to stderr and the program exits with the error code 98.
 *
 * Return: 0 on success, or exit code on failure.
 */


int main(int argc, char *argv[])
{
int dir = open(argv[1], O_RDONLY);
if (argc != 2)
{
fprintf(stderr, "Usage : %s elf_filename\n", argv[0]);
exit(98);
}

if (dir == -1)
{
fprintf(stderr, "Error : Failed to open file '%s'\n", argv[1]);
exit(98);
}

display_elf_header(dir);

close(dir);

return (0);
}
