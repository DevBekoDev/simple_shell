#include "shell.h"

/**
 *cmd_checker- checks for builtin func
 *@cmd: tokenized input
 *@buf: buffer
 *Return: 1 if cmd found 0 if not
 */
int cmd_checker(char **cmd, char *buf)
{
	if (my_builtins(cmd, buf))
		return (1);
	else if (**cmd == '/' || '.')
	{
		exec_command(cmd[0], cmd);
		return (1);
	}
	return (0);
}
/**
 * handle_ctrl_c - test
 * @signo: test
 */
void handle_ctrl_c(int signo)
{
	(void)signo;
	_putchar('\n');
	exit(EXIT_SUCCESS);
}
