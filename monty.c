#include "monty.h"

/**
 * process - Process monty file.
 * @filepath: The path to the file to process.
 */
void process(char *filepath)
{
	int fd;

	fd = open(filepath, O_RDONLY);
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filepath);
		exit(EXIT_FAILURE);
	}

	process_monty(fd);
}


/**
 * process_monty - Process monty file from
 *                 file descriptor using the stack.
 * @fd: A open file descriptor.
 */
void process_monty(int fd)
{
	stack_t *tail = NULL;
	char *line = NULL, *operator = NULL;
	int line_number = 0;

	while ((line = get_next_line(fd)) != NULL)
	{
		operator = strtok(line, " ");
		if (operator == NULL)
		{
			line_number++;
			continue;
		}

		if (!is_monty_operator(operator))
		{
			fprintf(stderr, "L%d: unknown instruction <%s>\n", line_number, operator);
			free_resources(&tail, fd, line);
			exit(EXIT_FAILURE);
		}

		if (handle_operator(
			&tail, line_number, operator,
			strtok(NULL, operator)) < 0
		)
		{
			free_resources(&tail, fd, line);
			exit(EXIT_FAILURE);
		}

		line_number++;
	}

	free_resources(&tail, fd, line);
}


/**
 * handle_operator - Handles a monty operator.
 *
 * @tail: A double pointer to the stack tail.
 * @line_number: The line number.
 * @operator: The operator string.
 * @args: The rest of the line content after the operator.
 *
 * Return: 1 on success, otherwise -1.
 */
int handle_operator(
	stack_t **tail,
	int line_number,
	char *operator,
	char *args
)
{
	/**
	 * printf("[%d]: Hanlde operator <%s> with args <%s>\n",
	 * line_number, operator, args);
	 */
	if (strcmp(operator, "push") == 0)
		return (handle_push(tail, line_number, args));

	pall(*tail);
	return (1);
}


/**
 * is_monty_operator - Checks if a string is a monty
 *                     operator.
 * @op: The string to check.
 *
 * Return: 1 if true, otherwise 0.
 */
char is_monty_operator(char *op)
{
	int i;
	const char *OPERATORS[2] = {
		"push",
		"pall"
	};

	for (i = 0; i <= 1; i++)
	{
		if (strcmp(OPERATORS[i], op) == 0)
			return (1);
	}

	return (0);
}


/**
 * free_resources - Frees resources.
 * @top: A double pointer to the stack's top.
 * @fd: The open file descriptor.
 * @line: The line pointer.
 */
void free_resources(stack_t **top, int fd, char *line)
{
	close(fd);
	free_stack(*top);
	free(line);
}
