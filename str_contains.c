#include "monty.h"

/*
 * str_contains - Verifies if a string contains a specific character.
 *
 * @s: The string to check.
 * @c: The character to find.
 * Return: 1 if the character is found, 0 otherwise.
 * Author: Amira
 */

int str_contains(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}
