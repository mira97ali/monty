#include "monty.h"

/**
 * get_op - Returns the function pointer for the given opcode.
 * @opcode: The opcode to search for.
 * Return: Function pointer to the opcode's corresponding function.
 */
void (*get_op(char *opcode))(stack_t **, MontyData *, unsigned int)
{
	instruction_t opcodes[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
		{NULL, NULL}
	};

	int i = 0;

	while (opcodes[i].opcode != NULL)
	{
		if (string_compare(opcodes[i].opcode, opcode) == 0)
			return (opcodes[i].f);
		i++;
	}

	return (NULL);
}
