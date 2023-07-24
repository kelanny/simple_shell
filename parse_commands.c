#include "main.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * **_arg_parser - Parse user input and tokenize it.
 * @lineptr: A pointer to the text buffer.
 * Return: a Pointer to an array of pointers to args.
 */

char **_arg_parser(char *lineptr)
{
	char *token, *temp, delim[] = " \n";
	char **tokens;
	size_t word_count = 0;
	int arg_count = 0;

	temp = strdup(lineptr);
	if (temp == NULL)
		perror("Strdup");
	token = strtok(temp, delim);
	while (token != NULL)
	{
		word_count++;
		token = strtok(NULL, delim);
	}
	free(temp);

	tokens = malloc(sizeof(char *) * (word_count + 1));
	if (!tokens)
	{
		perror("Malloc");
		exit(EXIT_FAILURE);
	}
	token = strtok(lineptr, delim);
	while (token != NULL)
	{
		tokens[arg_count] = strdup(token);
		token = strtok(NULL, delim);
		arg_count++;
	}
	tokens[arg_count] = NULL;
	free(lineptr);
	return (tokens);

}

/**
 * start_process - Start's a process that execute user commands.
 * @args: A Pointer to a string pointer of user commands
 *
 * Return: Nothing.
 */

void start_process(char **args)
{
	pid_t new_pid;

	new_pid = fork();
	if (new_pid == -1)
		perror("fork");
	if (new_pid == 0)
	{
		execve(args[0], args, NULL);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}

