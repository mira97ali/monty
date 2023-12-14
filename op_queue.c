#include "monty.h"

/*
 * op_queue - Configures the data format as a queue (FIFO).
 * @stack: Pointer to the head of the stack.
 * @data: MontyData structure containing necessary information.
 * @line_number: Line number of the instruction.
 * Author: Amira
 */

void op_queue(stack_t **stack, MontyData *data, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	data->lifo = 0;
}
