#include "monty.h"


/**
 * main - Entry point for the Monty interpreter.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 *
 * This function orchestrates the execution of the Monty interpreter. It
 * validates input, initializes data structures, processes each line of the
 * Monty file, and performs memory cleanup upon completion.
 *
 * Return: 0 on successful execution.
 */
int main(int argc, char *argv[])
{
	MontyData data;
	FILE *file;
	char *opcode;
	size_t bufsize;

	file = validate_input(argc, argv);
	initialize_data(
		&data.lifo,
		&data.cont,
		&data.arg,
		&data.head,
		&data.fd,
		&data.buffer
	);

	bufsize = 0;

	while (getline(&data.buffer, &bufsize, data.fd) != -1)
	{
		data.cont++;
		opcode = tokenize_string(data.buffer, " \t\n");
		if (opcode && opcode[0] != '#')
		{
			get_opcode_function(opcode)(&data.head, data.cont);
		}
	}

	free_data(data.head, data.fd, data.buffer);
	fclose(file);
	return (0);
}
