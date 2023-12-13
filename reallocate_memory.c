#include "monty.h"

/**
 * reallocate_memory - Reallocates memory for a node.
 *
 * @ptr: Pointer to the old memory.
 * @old_size: Old size of the memory.
 * @new_size: New size of the memory.
 * Return: Pointer to the reallocated memory.
 */
void *reallocate_memory(void *ptr, size_t old_size, size_t new_size)
{
	void *new_ptr;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		new_ptr = allocate_memory(new_size);
		return (new_ptr);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (new_size > old_size)
	{
		for (size_t i = 0; i < old_size; i++)
			((char *)new_ptr)[i] = ((char *)ptr)[i];
		free(ptr);
	}
	else
	{
		for (size_t i = 0; i < new_size; i++)
			((char *)new_ptr)[i] = ((char *)ptr)[i];
		free(ptr);
	}

	return (new_ptr);
}
