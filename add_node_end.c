#include "monty.h"

/* 
 * add_node_end - Inserts a new node at the end of the stack
 *
 * @head: Double pointer to the stack's linked list
 * @n: Value to be stored in the new node
 * Author: Amira.
 * Return: Pointer to the newly added node
 */

stack_t *add_node_end(stack_t **head, const int n)
{
	stack_t *new_node, *temp;

	if (!head)
		return (NULL);

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->next = NULL;

	if (!*head)
	{
		new_node->prev = NULL;
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	temp = *head;
	while (temp->next)
		temp = temp->next;

	new_node->next = temp->next;
	new_node->prev = temp;
	temp->next = new_node;

	return (temp->next);
}
