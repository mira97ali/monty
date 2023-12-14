#include "monty.h"

/**
* op_sub - Subtracts the top element of the stack from the second top element.
* @stack: Pointer to the head of the stack.
* @data: MontyData structure containing necessary information.
* @line_number: Line number of the instruction.
*/
void op_sub(stack_t **stack, MontyData *data, unsigned int line_number)
{
	int result;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_data(*stack, data->fd, data->buffer);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n - (*stack)->n;
	(*stack)->next->n = result;

	op_pop(stack, data, line_number);
}

