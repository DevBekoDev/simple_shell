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
 * @string: valuse entered
 * Return: void
 */

void _printf(char *string)
{
	int i = 0;

	for (; string[i] != '\0'; i++)
	{
		_putchar(string[i]);
	}
}


