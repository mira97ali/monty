#include "monty.h"

/**
 * tokenize_string - Breaks down a string into tokens using delimiters.
 *
 * @s: String to tokenize.
 * @delimiters: Delimiters to use for tokenization.
 * Return: A null-terminated string containing the tokens separated by space.
 * Author: Amira
 */

char *tokenize_string(char *s, char *delimiters)
{
	char *token;
	char *result = NULL;
	size_t result_size = 0;

	token = strtok(s, delimiters);
	while (token != NULL)
	{
		size_t token_len = strlen(token);

		result = reallocate_memory(result, result_size, result_size + token_len + 2);

		if (result_size > 0)
			result[result_size] = ' ';

		strcpy(result + result_size + 1, token);
		result_size += token_len + 1;
		token = strtok(NULL, delimiters);
	}

	if (result_size > 0)
		result[result_size] = '\0';

	return (result);
}
