#include "monty.h"

/**
 * main - Program entry point.
 * @argc: The number of arguments passed
 *        to the program.
 * @argv: Argument list.
 *
 * Return: EXIT_SUCESS on success otherwise
 *         EXIT_FAILURE.
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	process(argv[1]);

	exit(EXIT_SUCCESS);
}
