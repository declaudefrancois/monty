#include "monty.h"


/**
 * handle_push - Handles the push operator.
 *
 * @tail: A double pointer the the top of the stack.
 * @line_number: The line number.
 * @args: The argument string.
 *
 * Return: 1 on success or -1 on failure.
 */
int handle_push(stack_t **tail, int line_number, char *args)
{
	int n;

	if (!args)
	{
		fprintf(stderr, "L%d: usage: push integer", line_number);
		return (-1);
	}

	n = atoi(args);
	push(tail, n);
	return (1);
}

