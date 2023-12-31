#ifndef SHELL_H
#define SHELL_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <time.h>

void handle_ctrl_c(int signo);

int _putchar(char c);
int _printf(char *s);
void prompt(void);
void user_input(char *command, size_t size);
void exec_command(char *cp, char **cmd);
void free_buffers(char **buf);
char *add_path(char *path, char *command);
int _strncmp(char *s1, char *s2, int n);
int cmd_checker(char **cmd, char *buf);
void mode_handler(int s);
char **parse_args(char *command);
char *printError(void);
int _str_cmp(char *s1, char *s2);
char **my_tokenizer(char *line);
int _strlen(char *s);
void handle_env(void);
int my_builtins(char **command, char *line);
void my_exit(char **command, char *line);
char *_strdup(char *s);
char *_strchr(char *s, char c);
char *confirm_path(char **path, char *command);
char *get_path(void);

/**
 * struct flags - handle flags
 * @interactive: mode of the shell
 */
struct flags
{
	bool interactive;
} flags;

/**
 * struct builtins - builtins commands
 * @env: prints enviroment values
 * @exit: exit the shell
 */
struct builtins
{
	char *env;
	char *exit;
} builtins;
/**
 * struct cond - condition of the shell
 * @final_exit: shell exit
 * @ln_count: line count
 */
struct cond
{
	int final_exit;
	int ln_count;
} cond;
extern char **environ;

#endif
