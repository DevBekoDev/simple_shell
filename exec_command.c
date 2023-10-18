#include "shell.h"

/**
 * exec_command - execute commands
 * @cmd: entered by the user
 * @cp: user input
 */

void exec_command(char *cp, char **cmd)
{
	pid_t child_pid;
	int status;
	char **env = environ;

	child_pid = fork();
	if (child_pid < 0)
		perror(cp);
	if (child_pid == 0)
	{
		execve(cp, cmd, env);
		perror(cp);
		/* free(cp); */
		/* free_buffers(cmd); */
		exit(98);
	}
	else
		wait(&status);
}
