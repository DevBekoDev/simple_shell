#include "shell.h"

/**
 * main - run the shell
 * Return: 0
 */

int main(void)
{
	char command[128];

	while (1)
	{
		prompt();
		user_input(command, sizeof(command));
		exec_command(command);
	}
	return (0);
}
