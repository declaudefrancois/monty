#include "monty.h"


/**
 * get_next_line - Get the next line in the file
 *                 referenced by the fd.
 *
 * @fd: A open file descritptor.
 *
 * Return: A pointer to containing the next line.
 */
char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE];
	static char *bufferPtr = buffer;
	static int bytesLeft;

	char *lineStart = bufferPtr;
	char *lineEnd = NULL;
	ssize_t bytesRead;
	char *lastLine;
	int i;

	while (1)
	{
		lineEnd = strchr(lineStart, '\n');

		if (lineEnd != NULL)
		{
			*lineEnd = '\0';
			bufferPtr = lineEnd + 1;
			return (lineStart);
		}
		else
		{
			int remainingBytes = buffer + bytesLeft - lineStart;
			for (i = 0; i < remainingBytes; i++)
			{
				buffer[i] = lineStart[i];
			}
			bufferPtr = buffer + remainingBytes;
			bytesLeft = remainingBytes;
		}

		bytesRead = read(fd, bufferPtr, BUFFER_SIZE - bytesLeft - 1);
		if (bytesRead <= 0)
		{
			if (bytesLeft > 0)
			{
				*bufferPtr = '\0';
				lastLine = lineStart;
				lineStart = NULL;
				bytesLeft = 0;
				return (lastLine);
			}
			else
			{
				return (NULL);
			}
		}

		bufferPtr[bytesRead] = '\0';
		bytesLeft += bytesRead;
		lineStart = buffer;
	}
}
