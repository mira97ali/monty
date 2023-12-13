#include <stdio.h>
#include "monty.h"


/**
 * parse_instructions - Parse Monty bytecode instructions from a file
 * @file: Pointer to the open file containing Monty bytecode
 * @stack: Double pointer to the top of the stack
 * @opcodes: Array of opcode structures
 *
 * Description:
 * This function reads Monty bytecode instructions line by line.
 * For each line, it searches for a matching opcode
 * and executes the corresponding function.
 * If an unknown opcode is encountered,
 * it prints an error message and exits the program.
 */

void parse_instructions(FILE *file, stack_t **stack, instruction_t *opcodes)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	int i;

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;

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
}
