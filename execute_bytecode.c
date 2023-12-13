#include "monty.h"

/**
 * execute_bytecode - Execute Monty bytecode instructions from a file
 * @filename: The path to the file containing Monty bytecode
 * @stack: Double pointer to the top of the stack
 * @opcodes: Array of opcode structures
 *
 * Description: This function reads and processes Monty bytecode
 * instructions from the specified file.
 */

void execute_bytecode(
	const char *filename,
	stack_t **stack,
	instruction_t *opcodes)
{
	FILE *file;

	file = fopen(filename, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	parse_instructions(file, stack, opcodes);

	fclose(file);
}
