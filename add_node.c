#include "monty.h"

/*
 * add_node - Appends a new node to the stack
 *
 * @head: Double pointer to the stack's linked list
 * @n: Value to be stored in the new node
 * Return: Pointer to the newly added node
 * Author: Amira
 */

stack_t *add_node(stack_t **head, const int n)
{
	stack_t *new_node;

	if (!head)
		return (NULL);

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;

	if (*head)
		(*head)->prev = new_node;

	*head = new_node;
	return (new_node);
}
