#include "monty.h"

/**
 * string_compare - Determines the relationship between two strings.
 *
 * @s1: First string to be compared.
 * @s2: Second string to be compared.
 * Return: 0 if s1 and s2 are equal, 1 if s1 is greater, -1 if s2 is greater.
 * Author: Amira
 */

int string_compare(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;

	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);

	return (0);
}
