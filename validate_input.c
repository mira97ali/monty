#include "monty.h"

/*
 * validate_input - Verifies the input arguments and file for validity.
 *
 * @argc: Argument count.
 * @argv: Argument vector.
 * Return: FILE pointer to the opened file.
 * Author: Amira
 */

FILE *validate_input(int argc, char *argv[])
{
	FILE *fd;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (fd);
}
