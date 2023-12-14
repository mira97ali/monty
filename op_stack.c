#include "monty.h"

/**
 * op_stack - Sets the format of the data to a stack (LIFO).
 * @stack: Pointer to the head of the stack.
 * @data: MontyData structure containing necessary information.
 * @line_number: Line number of the instruction.
 */
void op_stack(stack_t **stack, MontyData *data, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	data->lifo = 1;
}
