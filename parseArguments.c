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

/**
* get_path - finds path global enviroment
* Return: NULL
*/
char *get_path(void)
{
	int x;
	char **env = environ, *path = NULL;

	/* Loop through global environment strings until a NULL pointer is found */
	while (*env)
	{
		/* Check if the current environment string starts with "PATH=" */
		if (_strncmp(*env, "PATH=", 5) == 0)
		{
			/* If "PATH=" is found, set the path pointer to the value of PATH */
			path = *env;
			while (*path && x < 5)
			{
				path++;
				x++;
			}
			return (path);
		}
		env++;
	}
	return (NULL);
}

/**
* add_path - adds path to command
* @path: path of command entered by the user
* @command: user input
* Return: buffer containing command on success or NULL
*/
char *add_path(char *path, char *command)
{
	char *buf;
	size_t i = 0, j = 0;

	/* Check if command is NULL, and if so, set it to an empty string */
	if (command == 0)
		command = "";

	if (path == 0)
		path = "";

	buf = malloc(sizeof(char) * (_strlen(path) + _strlen(command) + 2));
	if (!buf)
		return (NULL);

	while (path[i])
	{
		buf[i] = path[i];
		i++;
	}
	/* If the last character of the path is not '/', add '/' to the buffer */
	if (path[i - 1] != '/')
	{
		buf[i] = '/';
		i++;
	}
	while (command[j])
	{
		buf[i + j] = command[j];
		j++;
	}
	buf[i + j] = '\0';
	return (buf);
}

/**
* confirm_path - checks the path is valid
* @path: tokenized path from the user
* @command: user entered input
* Return: NULL
*/
char *confirm_path(char **path, char *command)
{
	int i = 0;
	char *output;

	while (path[i])
	{
		output = add_path(path[i], command);
		if (access(output, F_OK | X_OK) == 0)
			return (output);
		free(output);
		i++;
	}
	return (NULL);
}
