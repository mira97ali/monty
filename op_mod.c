#include "monty.h"

/**
 * op_mod - Computes the remainder of the division of the second top element
 *          of the stack by the top element.
 * @stack: Pointer to the head of the stack.
 * @data: MontyData structure containing necessary information.
 * @line_number: Line number of the instruction.
 * Author: Amira
 */

void op_mod(stack_t **stack, MontyData *data, unsigned int line_number)
{
	int result;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free_data(*stack, data->fd, data->buffer);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_data(*stack, data->fd, data->buffer);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n % (*stack)->n;
	(*stack)->next->n = result;

	op_pop(stack, data, line_number);
}
