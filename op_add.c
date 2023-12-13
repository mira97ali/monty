#include "monty.h"

/**
 * op_add - Adds the top two elements of the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number of the instruction.
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_data(*stack, data.fd, data.buffer);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->n + (*stack)->next->n;
	op_pop(stack, line_number);  /* Pop the top element */
	(*stack)->n = sum;
}
