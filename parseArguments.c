#include "shell.h"

/**
 * **parse_args - Parsing Argruments
 * @command: char
 * Return: char
 */

char** parse_args(char* command) {
  char** args = malloc(sizeof(char*) * 10);
  if (args == NULL) {
    perror("malloc");
    exit(1);
  }

  char* token = strtok(command, " ");
  int argc = 0;
  while (token != NULL && argc < 10) {
    args[argc++] = token;
    token = strtok(NULL, " ");
  }
  args[argc] = NULL;

  return args;
}
