#include "monty.h"

/**
 * op_push - Pushes an element to the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number of the instruction.
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	char *arg = data.arg;

	if (!arg || !isdigit(*arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_data(data.head, data.fd, data.buffer);
		exit(EXIT_FAILURE);
	}

	if (data.lifo)
		add_node(stack, atoi(arg));
	else
		add_node_end(stack, atoi(arg));
}
