#include "monty.h"

/**
 * op_swap - Swaps the top two elements of the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number of the instruction.
 */
void op_swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_data(*stack, data.fd, data.buffer);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
