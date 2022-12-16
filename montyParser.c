#include "monty.h"

/**
 *
 * parse_monty_file - Parses a monty file.
 *
 * @fd: File descriptor of the file to file.
 * The file must be opened with at least reading enabled.
 *
 * Return: EXIT_SUCCESS.
 */
int parseMontyFile(int fd)
{
	char line[BUFF_SIZE];
	off_t offset = 0;
	int lineNum = 1;

	while (_read_line(line, fd, BUFF_SIZE, &offset) != -1)
	{
		printf("%s\n", line);
		++lineNum;
	}
	printf("Line %d\n", lineNum);
	return (EXIT_SUCCESS);
}

