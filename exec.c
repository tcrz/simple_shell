#include "header.h"

void printnum(int n)
{
	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}

	if (n == 0)
		_putchar('0');

	if (n / 10 != 0)
		printnum(n / 10);

	_putchar(n % 10 + '0');
}

void errormsg(char *filename, char *args, int count)
{
	_print(filename);
	_print(": ");
	printnum(count);
	_print(": ");
	_print(args);
	_print(": not found\n");
}

/**
 *execute - run a command
 *@args: the command extracted from shell.c
 *Return: NULL
 *
 */

int execute(char *filename, char **args, int count)
{
	int i, id, status;
	char *firstarg = args[0];
	char *builtins_cmd[] = {"env", "exit", "cd"};
	int builtins_num = sizeof(builtins_cmd) / sizeof(char *);

	if (!args[0] || args[0] == "\t")
		return (1);

	for (i = 0; i < builtins_num; i++)
	{
		if (_strcmp(args[0], builtins_cmd[i]) == 0)
			return ((*builtins_func[i])(args));
	}
	if (_strncmp(firstarg, "/", 1) != 0)
		firstarg = _strcat(args[0]);
	if (access(firstarg, X_OK))
	{
		errormsg(filename, args[0], count);
		return (1);
	}
	id = fork();
	if (id < 0)
	{
		_print("Fork failed");
		exit(EXIT_FAILURE);
	}
	if (id == 0)
	{
		if (execve(firstarg, args, NULL) == -1)
			perror("error");
		exit(EXIT_FAILURE);
	}
	else
		wait(&status);
	return (1);
}
