#include "shell.h"

/**
 * **parse_args - Parsing Argruments
 * @command: char
 * Return: char
 */

char **parse_args(char *command)
{
	char **args = malloc(sizeof(char *) * 10);
	char *tokentemp = NULL;
	int argc = 0;

	if (args == NULL)
	{
		perror("malloc");
		exit(1);
	}

	tokentemp = strtok(command, " ");
	while (tokentemp != NULL && argc < 10)
	{
		args[argc++] = tokentemp;
		tokentemp = strtok(NULL, " ");
	}
	args[argc] = NULL;
	return (args);
}
