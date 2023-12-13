#include "monty.h"


/**
 * main - Entry point for the Monty program
 * @argc: The number of command-line arguments
 * @argv: An array containing the command-line arguments
 *
 * Description: The main function of the Monty program.
 *
 * Return: Always returns 0 on success.
 */

int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	execute_bytecode(argv[1], &stack, opcodes);

	return (0);
}
