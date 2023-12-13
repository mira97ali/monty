#include "monty.h"

/**
 * add_node_end - Adds a new node to the end of the stack
 *
 * @head: Pointer to the pointer to the stack linked list
 * @n: Value to be added to the new node
 * Return: Pointer to the new node
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
		*head = new_node;
		return (new_node);
	}

	temp = *head;
	while (temp->next)
		temp = temp->next;

	temp->next = new_node;
	new_node->prev = temp;

	return (new_node);
}