#include "monty.h"

/**
 * is_numeric - Checks if a string is a numeric value
 * @str: The string to check
 * Return: 1 if numeric, 0 otherwise
 */

int is_numeric(const char *str)
{
	int i;

	if (str == NULL || *str == '\0' || *str == '\n')
		return (0);

	i = 0;

	for (; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]) && (i == 0 && str[i] != '-' && str[i] != '+'))
			return (0);
	}

	return (1);
}
