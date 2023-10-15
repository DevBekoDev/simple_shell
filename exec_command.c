#include "shell.h"

/**
 * exec_command - execute commands
 * @command: entered by the user
 */

void exec_command(char **command)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		execve(command[0], command, (char **) NULL);
		perror("execlp");
		exit(EXIT_FAILURE);
	}
	else
	{

		wait(NULL);
	}
}
