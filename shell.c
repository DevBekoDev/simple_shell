#include "shell.h"

/**
 * main - run the shell
 * Return: 0
 */

int main(void)
{
	char command[128];
	char **args;

	while (1)
	{
		prompt();
		user_input(command, sizeof(command));
		if (str_cmp(command, "exit") == 0)
			exit(0);
		args = parse_args(command);
		exec_command(args);
	}
	return (0);
}
