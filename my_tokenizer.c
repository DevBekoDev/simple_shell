#include "shell.h"

/**
* my_tokenizer - creates tokens for user commands
* @line: commands entered by the user
*
* Return: array
*/
char **my_tokenizer(char *line)
{
	char *buf = NULL, *bufp = NULL, *token = NULL, *delim = " :\t\r\n";
	char **tokens = NULL;
	int tokensize = 1;
	size_t index = 0, flag = 0;

	/* Duplicate the input line to avoid modifying the original string */
	buf = _strdup(line);
	if (!buf)
		return (NULL);
	bufp = buf;

	/* Count the number of tokens in the line */
	while (*bufp)
	{
		if (_strchr(delim, *bufp) != NULL && flag == 0)
		{
			tokensize++;
			flag = 1;
		}
		else if (_strchr(delim, *bufp) == NULL && flag == 1)
			flag = 0;
		bufp++;
	}
	/* Allocate memory for the array of tokens */
	tokens = malloc(sizeof(char *) * (tokensize + 1));
	token = strtok(buf, delim);
	while (token)
	{/* Duplicate the token and store it in the tokens array */
		tokens[index] = _strdup(token);
		if (tokens[index] == NULL)
		{
			free(tokens);
			return (NULL);
		}
		token = strtok(NULL, delim);
		index++;
	}
	tokens[index] = '\0';
	free(buf);
	return (tokens);
}
