#include "shell.h"

/**
 * _isAlpha - check character is alphabet or not
 * @c: char
 * Return: int
 */
int _isAlpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

/**
 * checkRequirements - check for project requirements
 * @str: string
 * Return: int
 */

int checkRequirements(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (!_isAlpha(str[i]))
			return (1);
		i++;
	}
	return (0);
}
