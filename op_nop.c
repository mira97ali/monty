#include "monty.h"

/**
 * op_nop - Does nothing.
 * @stack: Pointer to the head of the stack.
 * @data: MontyData structure containing necessary information.
 * @line_number: Line number of the instruction.
 */
void op_nop(stack_t **stack, MontyData *data, unsigned int line_number)
{
	(void)stack;
	(void)data;
	(void)line_number;
	/* Do nothing */
}
