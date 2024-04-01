#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define BUFFER_SIZE 1024

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
 * process - Process monty file.
 * @filepath: The path to the file to process.
 */
void process(char *filepath);

/**
 * process_monty - Process monty file from
 *                 file descriptor using the stack.
 * @fp: A open file descriptor.
 */
void process_monty(int fd);


/**
 * pop - Removes an items from the stack.
 * @tail: A double pointer to the tail
 *         of the list.
 */
stack_t *pop(stack_t **tail);


/**
 * push - Adds an items to the stack.
 * @tail: A double pointer to the tail
 *         of the list.
 * Returns: 1 on success or -1 on failure.
 */
int push(stack_t **tail, int n);

/**
 * free_stack - Frees the memory used by the stack.
 * @tail: A double pointer to the tail of the stack.
 */
void free_stack(stack_t *tail);


/**
 * pall - Prints all node of the stack.
 *
 * @top: A pointer to the top of the stack.
 *
 * Returns; Always 1.
 */
int pall(stack_t *top);

/**
 * is_monty_operator - Checks if a string is a monty
 *                     operator.
 * @op: The string to check.
 *
 * Returns: 1 if true, otherwise 0.
 */
char is_monty_operator(char *op);

/**
 * handle_operator - Handles a monty operator.
 *
 * @stack: A double pointer to the stack tail.
 * @line_number: The line number.
 * @operator: The operator string.
 * @args: The rest of the line content after the operator.
 *
 * Returns: 1 on success, otherwise -1.
 */
int handle_operator(stack_t **tail, int line_number,  char *operator, char *args);


/**
 * handle_push - Handles the push operator.
 *
 * @tail: A double pointer the the top of the stack.
 * @line_number: The line number.
 * @args: The argument string.
 *
 * Return: 1 on success or -1 on failure.
 */
int handle_push(stack_t **tail, int line_number, char *args);


/**
 * free_resources - Frees resources.
 * @top: A double pointer to the stack's top.
 * @fd: The open file descriptor.
 * @line: The line pointer.
 */
void free_resources(stack_t **top, int fd, char *line);

/**
 * get_next_line - Get the next line in the file
 *                 referenced by the fd.
 *
 * @fd: A open file descritptor.
 *
 * Return: A pointer to containing the next line.
 */
char *get_next_line(int fd);

#endif /** MONTY_H */
