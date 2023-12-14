#include "monty.h"

/*
 * op_pint - Displays the value at the top of the stack.
 * @stack: Pointer to the head of the stack.
 * @data: MontyData structure containing necessary information.
 * @line_number: Line number of the instruction.
 * Author: Amira
 */

void op_pint(stack_t **stack, MontyData *data, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_data(*stack, data->fd, data->buffer);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
