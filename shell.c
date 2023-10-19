#include "shell.h"
/**
* main - run the shell
* @ac: argument counted from the user
* @av: argument vector from the user
* @envp: environment value
* Return: 0
*/

int main(int ac, char **av, char *envp[])
{
	char *line = NULL, *pathcommand = NULL, *path = NULL;
	size_t buffsize = 0;
	ssize_t linesize = 0;
	char **command = NULL, **paths = NULL;
	(void)envp, (void)av;
	if (ac < 1)
		return (-1);
	signal(SIGINT, mode_handler);
	/*signal(SIGINT, handle_ctrl_c);*/
	while (1)
	{
		free_buffers(paths);
		free_buffers(command);
		free(pathcommand);
		prompt();
		linesize = getline(&line, &buffsize, stdin);
		if (linesize < 0)
			break;
		cond.ln_count++;
		if (line[linesize - 1] == '\n')
			line[linesize - 1] = '\0';
		command = my_tokenizer(line);
		if (command == NULL || *command == NULL || **command == '\0')
			continue;
		if (cmd_checker(command, line))
			continue;
		path = get_path();
		paths = my_tokenizer(path);
		pathcommand = confirm_path(paths, command[0]);
		if (!pathcommand)
			perror(av[0]);
		else
			exec_command(pathcommand, command);
	}
	if (linesize < 0 && flags.interactive)
		write(STDERR_FILENO, "\n", 1);
	free(line);
	return (0);
}
