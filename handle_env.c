#include "shell.h"

/**
* handle_env - prints environment string to stdout
*
* Return: 0
*/
void handle_env(void)
{
	int x = 0;
	char **env = environ;

	/* Loop through the environment strings until a NULL pointer is encountered */
	while (env[x])
	{
		write(STDOUT_FILENO, (const void *)env[x], _strlen(env[x]));
		write(STDOUT_FILENO, "\n", 1);
		x++;
	}
}
