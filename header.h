#ifndef _HEADER_
#define _HEADER_
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

ssize_t getline(char **lineptr, size_t *n, FILE *stream);
extern char** environ;

extern char *builtins_cmd[];
extern int (*builtins_func[]) (char **);

int _putchar(char str);
void _print(char *str);
int _strlen(char *str);
char *_strcat(char *str);
int _strcmp(char *str, char *strcmp);
int _strncmp(char *s1, char *s2, size_t n);

int execute(char **args);
int  env_func(char **args);
int cd_func(char **args);
int exit_func(char **args);
int num_of_builtins();

#endif
