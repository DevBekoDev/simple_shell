#include "shell.h"

/**
* my_builtins - execute built ins commands
* @command: tokenized input
* @line: input read from user
* Return: 1 if found, 0 if not
*/
int my_builtins(char **command, char *line)
{
	/* Define a struct to store the names of built-in commands */
	struct builtins builtins = {"env", "exit"};

	if (_str_cmp(*command, builtins.env) == 0)
	{
		handle_env();
		return (1);
	}
	else if (_str_cmp(*command, builtins.exit) == 0)
	{
		my_exit(command, line);
		return (1);
	}
	else if (signal(SIGINT, handle_ctrl_c) == SIG_ERR)
	{
		exit(EXIT_SUCCESS);
	}
	return (0);
}
