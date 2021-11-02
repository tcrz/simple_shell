#ifndef _HEADER_
#define _HEADER_
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>


extern char** environ;

extern int (*builtins_func[]) (char **);

int _putchar(char str);
void _print(char *str);
int _strlen(char *str);
char *_strcat(char *str);
int _strcmp(char *str, char *strcmp);
int _strncmp(char *s1, char *s2, size_t n);

void printnum(int n);
void errormsg(char *filename, char *args, int count);
int execute(char *filename, char **args, int count);
int  env_func();
int cd_func(char **args);
int exit_func();
int num_of_builtins();

#endif
