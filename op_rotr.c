#include "monty.h"

/*
 * op_rotr - Shifts the stack elements downward, rotating to the bottom.
 * @stack: Pointer to the head of the stack.
 * @data: MontyData structure containing necessary information.
 * @line_number: Line number of the instruction.
 * Author: Amira
 */

void op_rotr(stack_t **stack, MontyData *data, unsigned int line_number)
{
	stack_t *first, *last;

	(void)data;
	(void)line_number;

	if (stack && *stack && (*stack)->next)
	{
		first = *stack;
		last = *stack;

		while (last->next)
			last = last->next;

		last->prev->next = NULL;
		last->prev = NULL;
		last->next = first;
		first->prev = last;

		*stack = last;
	}
}
