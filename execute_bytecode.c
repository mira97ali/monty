#include "monty.h"

/**
 * execute_bytecode - Execute Monty bytecode instructions from a file
 * @filename: The path to the file containing Monty bytecode
 *
 * Description: This function reads and processes Monty bytecode
 * instructions from the specified file.
 */

void execute_bytecode(const char *filename)
{
	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	fclose(file);
}
