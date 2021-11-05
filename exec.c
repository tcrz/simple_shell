#include "header.h"

/**
 *printnum - prints number
 *@n: number
 */

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

/**
 *errormsg - run a command
 *@args: the command extracted from shell.c
 *@filename: name of main program
 *@count: counts number of executions
 */
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
 *@filename: name of main program
 *@count: counts number of executions
 *Return: 1 or 0 depending on command executed
 */

int execute(char *filename, char **args, int count)
{
	int i, id, status;
	char *firstarg, *builtins_cmd[] = {"env", "exit", "cd", "help"};
	int builtins_num = sizeof(builtins_cmd) / sizeof(char *);

	if (!args[0])
		return (1);
	for (i = 0; i < builtins_num; i++)
	{
		if (_strcmp(args[0], builtins_cmd[i]) == 0)
			return ((*builtins_func[i])(args));
	}
	firstarg = _strcat(args[0]);
	if (access(firstarg, X_OK))
	{
		errormsg(filename, args[0], count);
		if (_strcmp(args[0], firstarg) != 0)
			free(firstarg);
		return (1);
	}
	id = fork();
	if (id < 0)
	{
		_print("Fork failed");
		free(firstarg);
		exit(EXIT_FAILURE);
	}
	else if (id == 0)
	{
		if (execve(firstarg, args, NULL) == -1)
			perror("error");
		free(firstarg);
		exit(EXIT_FAILURE);
	}
	else
		{
			wait(&status);
			if (_strcmp(args[0], firstarg) != 0)
				free(firstarg);
		}
	return (1);
}
