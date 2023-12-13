#include "monty.h"

/**
 * free_list - Frees a stack linked list
 *
 * @head: Pointer to the stack linked list
 * Return: No return value
 */
void free_list(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
