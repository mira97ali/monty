#include "monty.h"

/*
 * op_stack - Configures the data format as a stack (LIFO).
 * @stack: Pointer to the head of the stack.
 * @data: MontyData structure containing necessary information.
 * @line_number: Line number of the instruction.
 * Author: Amira
 */

void op_stack(stack_t **stack, MontyData *data, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	data->lifo = 1;
}
