#include "monty.h"


/**
 * pall - Prints all the elements of the stack
 * @stack: Double pointer to the top of the stack
 *
 * Description: This function prints all the elements of the stack, starting
 * from the top. Each element is printed on a new line.
 */

void pall(stack_t **stack)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
