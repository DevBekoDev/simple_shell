#include "shell.h"

/**
 * *printError - print error message
 *
 * Return: string
 *
 */
char *printError(void)
{
	char *str = "No such file or directory";

	return (str);
}

/**
 * *tokenization - chunks the input to tokens
 * @str: string
 * Return: string
 */
char *tokenization(char *str)
{
	char *token;
	char *delim = "/";

	token = strtok(str, delim);
	while (token != NULL)
	{
		if (checkRequirements(token))
			return (printError());
		token = strtok(NULL, delim);
	}
	return (NULL);
}

/**
 * copyString - copying string
 * @s: string
 * @s2: string
 * Return: void
 */
void copyString(char s[], char *s2)
{
	strcpy(s2, s);
}

/**
 * *handleErrors - Handling command errors
 * @str: string
 * Return: string
 */
char *handleErrors(char *str)
{
	char cpycommand[256];
	char *error = NULL;

	if (!str)
		return (printError());
	if (str[0] != '/')
		return (printError());
	copyString(str, cpycommand);
	error = tokenization(cpycommand);
	if (error)
		return (error);
	return (str);
}
