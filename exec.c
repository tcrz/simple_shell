#include "header.h"

/**
 *execute - run a command
 *@args: the command extracted from shell.c
 *Return: NULL
 *
 */

int execute(char **args, char *file)
{
	int i, id, status;
	char *firstarg;

	if (!args[0])
		return 1;

	for (i = 0; i < num_of_builtins(); i++)
	{
		if (_strcmp(args[0], builtins_cmd[i]) == 0)
			return ((*builtins_func[i])(args));
	}

	firstarg = args[0];
	 if (_strncmp(firstarg, "/", 1) != 0)
		firstarg = _strcat(args[0]);

	if (access(firstarg, X_OK))
	{
		_print(file);
		_print(": ");
		_print(args[0]);
		_print(": not found\n");
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
