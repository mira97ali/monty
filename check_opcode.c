#include "monty.h"

/**
 * check_opcode - Checks if the given opcode is valid.
 * @opcode: The opcode to search for.
 * @line_number: Line number of the instruction.
 */
void check_opcode(char *opcode, int line_number)
{
	int i;
	char *valid_opcodes[] = {
		"push",
		"pall",
		"pint",
		"pop",
		"swap",
		"add",
		"nop",
		NULL
	};

	for (i = 0; valid_opcodes[i] != NULL; i++)
	{
		if (strcmp(valid_opcodes[i], opcode) == 0)
			return;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
