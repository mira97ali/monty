#include "monty.h"

/**
 * op_pop - Removes the top element of the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number of the instruction.
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_data(*stack, data.fd, data.buffer);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}
