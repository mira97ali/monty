#include "monty.h"

/*
 * op_pstr - Displays the string starting at the top of the stack.
 * @stack: Pointer to the head of the stack.
 * @data: MontyData structure containing necessary information.
 * @line_number: Line number of the instruction.
 * Author: Amira
 */

void op_pstr(stack_t **stack, MontyData *data, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)data;
	(void)line_number;

	while (current && current->n != 0 && (current->n >= 0 && current->n <= 127))
	{
		putchar(current->n);
		if (current->n == 0)
			break;
		current = current->next;
	}

	putchar('\n');
}
