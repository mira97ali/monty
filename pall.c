#include "monty.h"


/**
 * pall - Prints all the elements of the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number of the opcode in the Monty file
 *
 * Description: This function prints all the elements of the stack, starting
 * from the top. Each element is printed on a new line.
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)(line_number);

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
