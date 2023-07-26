#include "main.h"
#include <string.h>

/**
 * main - Entry point to simple shell program.
 * @ac: Number of commandline arguments passed
 * @av: A pointer to strings of arguments passed.
 * @ep: Pointer to system environment array.
 *
 * Return: Always 0 (Success)
 */

int main(int ac, char *av[], char *ep[])
{
	size_t n = 0;
	int len, mode = 1;
	char **args;
	char *line = NULL;
	ssize_t bytes_read;

	(void)ac;
	(void)av;
	(void)ep;
	while (mode)
	{
		mode = isatty(STDIN_FILENO);
		if (mode == 1)
		{
			write(STDIN_FILENO, "$ ", 3);
		}
		bytes_read = getline(&line, &n, stdin);
		if (bytes_read == -1)
		{
			if (feof(stdin))
			{
				write(1, "\n", 1);
				break;
			}
			else
			{
				perror("getline error");
				exit(EXIT_FAILURE);
			}
		}
		args = _arg_parser(line);
		if (strcmp(args[0], "exit") == 0)
		{
			exit(0);
		}
		else if (access(args[0], F_OK) == 0)
		{
			start_process(args);
		}
		else
			perror("access");
		for (len = 0; args[len] != NULL; len++)
		{
			free(args[len]);
			len++;
		}
		free(args);
	}
	return (0);
}
