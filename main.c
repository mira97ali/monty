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
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	execute_bytecode(argv[1]);

	return (0);
}

