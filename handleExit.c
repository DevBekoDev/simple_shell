#include "shell.h"
/**
 * _str_cmp - compare between two strings
 * @s1: char
 * @s2: char
 * Return: int
 */

int _str_cmp(char *s1, char *s2)
{
	int i = 0, output;

	while (*(s1 + i) == *(s2 + i) && *(s1 + i) != '\0')
		i++;

	output = (*(s1 + i) - *(s2 + i));

	return (output);
}

/**
* my_exit - handles exit command
* @command: tokenized command
* @line: input read
* Return: no return
*/
void my_exit(char **command, char *line)
{
	free(line);
	free_buffers(command);
	exit(EXIT_SUCCESS);
}
