#include "monty.h"

/**
 * op_pint - Prints the value at the top of the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number of the instruction.
 */
void op_pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_data(*stack, data.fd, data.buffer);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
