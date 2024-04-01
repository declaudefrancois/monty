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
		fprintf(stderr, "L<%d>: usage: push integer\n", line_number);
		return (-1);
	}

	n = atoi(args);
	push(tail, n);
	return (1);
}


/**
 * handle_pint - Handles the pint operator.
 * @line_number: The line number.
 * @top:  A double pointer to the top of the stack.
 *
 * Return: 1 on success or -1 on failure.
 */
int handle_pint(stack_t **top, int line_number)
{
	if (!(*top))
	{
		fprintf(stderr, "L<%d>: can't pint, stack empty\n", line_number);
		return (-1);
	}

	printf("%d\n", (*top)->n);
	return (1);
}



/**
 * handle_pop - Handles the pop operator.
 * @line_number: The line number.
 * @top:  A double pointer to the top of the stack.
 *
 * Return: 1 on success or -1 on failure.
 */
int handle_pop(stack_t **top, int line_number)
{
	stack_t *node;
        if (!(*top))
        {
                fprintf(stderr, "L<%d>: can't pop an empty stack\n", line_number);
                return (-1);
        }

        node = pop(top);
	if (node)
		free(node);

        return (1);
}

