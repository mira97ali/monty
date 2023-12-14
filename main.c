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
	ssize_t nlines;

	file = validate_input(argc, argv);
	initialize_data(
		&data.lifo,
		&data.cont,
		&data.arg,
		&data.head,
		&data.fd,
		&data.buffer
	);

	bufsize = 256;
	nlines = 0;
	while ((nlines = getline(&data.buffer, &bufsize, file)) != -1)
	{
		opcode = strtok(data.buffer, " \t\n");
		if (opcode)
		{
			check_opcode(opcode, data.cont);
			if (opcode && opcode[0] != '#')
			{
				data.arg = strtok(NULL, " \t\n");
				get_op(opcode)(&(data.head), &data, data.cont);
			}
		}
		data.cont++;
	}

	free_data(data.head, data.fd, data.buffer);
	fclose(file);
	return (0);
}
