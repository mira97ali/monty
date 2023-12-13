#include "monty.h"

/**
 * op_nop - Does nothing.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number of the instruction.
 */
void op_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	/* Do nothing */
}
