#include "monty.h"

/**
 * op_rotl - Rotates the stack to the top.
 * @stack: Pointer to the head of the stack.
 * @data: MontyData structure containing necessary information.
 * @line_number: Line number of the instruction.
 * Author: Amira
 */

void op_rotl(stack_t **stack, MontyData *data, unsigned int line_number)
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

		*stack = first->next;
		(*stack)->prev = NULL;

		first->next = NULL;
		first->prev = last;
		last->next = first;
	}
}
