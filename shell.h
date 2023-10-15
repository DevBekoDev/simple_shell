#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/types.h>
#include <sys/wait.h>
int _puthcar(char c);
void _printf(char *string);
void prompt(void);
void user_input(char *command, size_t size);
void exec_command(char **command);
void free_buffers(char **buf);
char **parse_args(char *command);
char *printError(void);
int str_cmp(const char *s1, const char *s2);
/**
 * struct flags - handle flags
 * @interactive: mode of the shell
 */
struct flags
{
	int interactive;
} flags;
#endif
