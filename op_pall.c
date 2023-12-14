#include "monty.h"

/*
 * op_pall - Displays all values on the stack.
 * @stack: Pointer to the head of the stack.
 * @data: MontyData structure containing necessary information.
 * @line_number: Line number of the instruction.
 * Author: Amira
 */

void op_pall(stack_t **stack, MontyData *data, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;
	(void)data;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
