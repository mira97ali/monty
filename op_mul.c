#include "monty.h"

/*
 * op_mul - Multiplies the first two elements of the stack.
 * @stack: Pointer to the head of the stack.
 * @data: MontyData structure containing necessary information.
 * @line_number: Line number of the instruction.
 * Author: Amira
 */

void op_mul(stack_t **stack, MontyData *data, unsigned int line_number)
{
	int result;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(
			stderr,
			"L%u: can't mul, stack too short\n",
			line_number
		);
		free_data(*stack, data->fd, data->buffer);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n * (*stack)->n;
	(*stack)->next->n = result;

	op_pop(stack, data, line_number);
}
