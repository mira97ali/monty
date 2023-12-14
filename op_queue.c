#include "monty.h"

/**
 * op_queue - Sets the format of the data to a queue (FIFO).
 * @stack: Pointer to the head of the stack.
 * @data: MontyData structure containing necessary information.
 * @line_number: Line number of the instruction.
 */
void op_queue(stack_t **stack, MontyData *data, unsigned int line_number)
{
	stack_t *temp, *last;

	(void)line_number;

	if (data->lifo == 1 || (*stack && (*stack)->next))
	{
		temp = *stack;
		last = *stack;

		while (last->next)
			last = last->next;

		*stack = temp->next;
		if (*stack)
			(*stack)->prev = NULL;

		temp->next = NULL;
		temp->prev = last;
		if (last)
			last->next = temp;

		data->lifo = 0;
	}
}
