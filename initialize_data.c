#include "monty.h"

/**
 * initialize_data - Sets up global variables for Monty interpreter.
 * @lifo: LIFO mode indicator.
 * @cont: Line number counter.
 * @arg: Argument for the current operation.
 * @head: Pointer to the head of the linked list.
 * @fd: File descriptor for Monty file.
 * @buffer: Buffer for reading lines from the file.
 *
 * This function initializes the global variables
 * used in the Monty interpreter.
 * Author: Amira
 */

void initialize_data(int *lifo, unsigned int *cont, char **arg,
					stack_t **head, FILE **fd, char **buffer)
{
	*lifo = 1;
	*cont = 1;
	*arg = NULL;
	*head = NULL;
	*fd = NULL;
	*buffer = NULL;
}
