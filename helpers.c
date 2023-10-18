#include "shell.h"

/**
* _strdup - dupicate a string
* @s: to duplicate
* Return: pointer to duplicated string
*/
char *_strdup(char *s)
{
	char *ptr;
	int i, len;

	if (s == NULL)
		return (NULL);

	len = _strlen(s);

	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	for (i = 0; *s != '\0'; s++, i++)
		ptr[i] = s[0];

	ptr[i++] = '\0';
	return (ptr);
}

/**
* _strchr - locate character in a string
* @s: string checked
* @c: character located
* Return: returns pointer to first charachter
*/
char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (!c)
		return (s);
	return (NULL);
}

/**
* _strlen - gives the length of a string
* @s: string entered
* Return: length of string passed
*/
int _strlen(char *s)
{
	int count = 0;

	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}

extern __sighandler_t signal(int __sig, __sighandler_t __handler);
/**
 *mode_handler - keeps track of shell mode
 *@s: signal num
 *Return: nothing
 */

void mode_handler(int s)
{
	(void)s;
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "$ ", 2);
}

/**
* _strncmp - compares two strings to n bytes
* @s1: compare to s2
* @s2: compare to s1
* @n: num of bytes
* Return: 0
*/
int _strncmp(char *s1, char *s2, int n)
{
	int i;

	for (i = 0; s1[i] && s2[i] && i < n; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}
