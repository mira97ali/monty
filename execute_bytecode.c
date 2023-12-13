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
	FILE *file = fopen(filename, "r");
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;

		int i;

		for (i = 0; opcodes[i].opcode != NULL; i++)
		{
			if (strncmp(line, opcodes[i].opcode, strlen(opcodes[i].opcode)) == 0)
			{
				opcodes[i].f(stack, line_number);
				break;
			}
		}

		if (opcodes[i].opcode == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction %s", line_number, line);
			free(line);
			fclose(file);
			exit(EXIT_FAILURE);
		}
	}

	free(line);
	fclose(file);
}
