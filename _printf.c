#include "shell.h"

/**
 * _putchar - writes the character c to stdout
 * @c: character to print
 * Return: 1 on success
 * -1 on error
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printf - a function to print things
 * @s: valuse entered
 * Return: void
 */

int _printf(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}

	return (i);
}
