#include "shell.h"
/**
 * _str_cmp - compare between two strings
 * @s1: char
 * @s2: char
 * Return: int
 */

int _str_cmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
		{
			if (*s1 > *s2)
				return (1);
			else
				return (-1);
		}
		s1++;
		s2++;
	}
	if (*s1 == '\0' && *s2 != '\0')
		return (-1);
	else if (*s1 != '\0' && *s2 == '\0')
		return (1);
	else
		return (0);
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
	exit(0);
}
