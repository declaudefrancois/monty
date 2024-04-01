#include "monty.h"

/**
 * pop - Removes an items from the stack.
 * @tail: A double pointer to the tail
 *         of the list.
 *
 * Return: A pointer to the node to pop.
 */
stack_t *pop(stack_t **tail)
{
	stack_t *node;

	node = *tail;
	if (*tail)
	{
		*tail = (*tail)->prev;
		(*tail)->next = NULL;
	}

	return (node);
}


/**
 * push - Adds an items to the stack.
 *
 * @tail: A double pointer to the tail
 *         of the list.
 * @n: The value of the node to add.
 *
 * Return: 1 on success or -1 on failure.
 */
int push(stack_t **tail, int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (!node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (-1);
	}

	node->n = n;
	node->next = NULL;
	node->prev = *tail;
	if (*tail)
		(*tail)->next = node;
	*tail = node;
	return (1);
}



/**
 * pall - Prints all node of the stack.
 *
 * @top: A pointer to the top of the stack.
 *
 * Return: Always 1.
 */
int pall(stack_t *top)
{
	while (top)
	{
		printf("%d\n", top->n);
		top = top->prev;
	}

	return (1);
}

/**
 * free_stack - Frees the memory used by the stack.
 * @tail: A double pointer to the tail of the stack.
 */
void free_stack(stack_t *tail)
{
	if (!tail)
		return;

	while (tail->prev)
	{
		tail = tail->prev;
		free(tail->next);
	}

	free(tail);
}
