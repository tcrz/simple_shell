#ifndef _HEADER_
#define _HEADER_
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>


int _putchar(char str);
void _print(char *str);
int _strlen(char *str);
int _strcmp(char *str, char *strcmp);
void execute(char **args);
char *_strcat(char *str);
#endif
