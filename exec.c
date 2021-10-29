#include "header.h"

/**
 *execute - run a command
 *@args: the command extracted from shell.c
 *Return: NULL
 *
 */


void execute(char **args)
{
	int id;
	int status;

	id = fork();
	if (id < 0)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	if (id == 0)
	{
		if (execve(_strcat(args[0]), args, NULL) == -1)
			perror("error!");
		exit(EXIT_FAILURE);
	}
	else
		wait(&status);

}
