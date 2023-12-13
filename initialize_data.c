#include "monty.h"

/**
 * initialize_data - Initializes the global variables for Monty interpreter.
 * @lifo: LIFO (Last In, First Out) mode indicator.
 * @cont: Line number counter.
 * @arg: Argument for the current operation.
 * @head: Pointer to the head of the linked list.
 * @fd: File descriptor for Monty file.
 * @buffer: Buffer for reading lines from the file.
 *
 * This function sets initial values for
 * the global variables used in the Monty interpreter.
 */
void initialize_data(int *lifo, unsigned int *cont, char **arg,
					stack_t **head, FILE **fd, char **buffer)
{
	*lifo = 1;
	*cont = 1;
	*arg = NULL;
	*head = NULL;
	*fd = NULL;
	*buffer = malloc(1024);

	if (*buffer == NULL) {
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}
