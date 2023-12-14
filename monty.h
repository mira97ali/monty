#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct MontyData - structure to hold data for the Monty interpreter.
 * @lifo: LIFO mode indicator.
 * @cont: Line number counter.
 * @arg: Argument for the current operation.
 * @head: Pointer to the head of the linked list.
 * @fd: File descriptor for Monty file.
 * @buffer: Buffer for reading lines from the file.
 *
 * Description: this structure encapsulates data elements
 * for the Monty interpreter,
 * providing a convenient way to organize and pass around
 * information related to the program's state.
 */

typedef struct MontyData
{
	int lifo;
	unsigned int cont;
	char *arg;
	stack_t *head;
	FILE *fd;
	char *buffer;
} MontyData;

/**
 * struct opcode_func - Structure for opcode and function mapping.
 * @opcode: String representing the opcode.
 * @f: Function pointer for the corresponding opcode function.
 *
 * Description: This structure maps an opcode string to its corresponding
 * function. This mapping is used to dynamically call the correct function
 * based on the given opcode.
 */
typedef struct opcode_func
{
	char *opcode;
	void (*f)(stack_t **, MontyData *, unsigned int);
} opcode_func_t;

ssize_t getline(char **lineptr, size_t *n, FILE *stream);

void op_push(stack_t **stack, MontyData *data, unsigned int line_number);
void op_pall(stack_t **stack, MontyData *data, unsigned int line_number);
void op_pint(stack_t **stack, MontyData *data, unsigned int line_number);
void op_pop(stack_t **stack, MontyData *data, unsigned int line_number);
void op_swap(stack_t **stack, MontyData *data, unsigned int line_number);
void op_add(stack_t **stack, MontyData *data, unsigned int line_number);
void op_nop(stack_t **stack, MontyData *data, unsigned int line_number);
void op_sub(stack_t **stack, MontyData *data, unsigned int line_number);
void op_div(stack_t **stack, MontyData *data, unsigned int line_number);
void op_mul(stack_t **stack, MontyData *data, unsigned int line_number);
void op_mod(stack_t **stack, MontyData *data, unsigned int line_number);
void op_pchar(stack_t **stack, MontyData *data, unsigned int line_number);
void op_pstr(stack_t **stack, MontyData *data, unsigned int line_number);

void check_opcode(char *opcode, int line_number);
void (*get_op(char *opcode))(stack_t **, MontyData *, unsigned int);

int str_contains(char *s, char c);
char *tokenize_string(char *s, char *delimiters);
void *reallocate_memory(void *ptr, size_t old_size, size_t new_size);
void *allocate_memory(size_t size);
int string_compare(char *s1, char *s2);

stack_t *add_node_end(stack_t **head, const int n);
stack_t *add_node(stack_t **head, const int n);
void free_list(stack_t *head);

void free_data(stack_t *head, FILE *fd, char *buffer);
void initialize_data(int *lifo, unsigned int *cont, char **arg,
					stack_t **head, FILE **fd, char **buffer);
FILE *validate_input(int argc, char *argv[]);

#endif
