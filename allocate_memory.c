#include "monty.h"

/**
 * allocate_memory - Reserves memory for a new node.
 *
 * @size: Size of the memory to be allocated.
 * Return: Pointer to the allocated memory.
 * Author: Amira
 */

void *allocate_memory(size_t size)
{
	void *ptr;

	ptr = malloc(size);
	if (ptr == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	return (ptr);
}
