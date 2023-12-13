#include "monty.h"

/**
 * free_data - Frees allocated data and closes the file
 *
 * @head: Pointer to the stack linked list
 * @fd: Pointer to the file descriptor
 * @buffer: Pointer to the input buffer
 * Return: No return value
 */
void free_data(stack_t *head, FILE *fd, char *buffer)
{
	free_list(head);
	if (buffer != NULL) {
        free(buffer);
    }
	if (fd != NULL) {
        fclose(fd);
    }
}
