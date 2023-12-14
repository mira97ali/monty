#include "monty.h"

/*
 * check_opcode - Verifies the validity of the given opcode.
 * @opcode: The opcode to search for.
 * @line_number: Line number of the instruction.
 * Author: Amira
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
		"sub",
		"div",
		"mul",
		"mod",
		"pchar",
		"pstr",
		"rotl",
		"rotr",
		"stack",
		"queue",
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
