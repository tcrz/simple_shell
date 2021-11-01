#include "header.h"

/**
 *execute - run a command
 *@args: the command extracted from shell.c
 *Return: NULL
 *
 */

int execute(char **args)
{
	int i, id, status;

	 if (!args[0])
		args[0] = "";
	for (i = 0; i < num_of_builtins(); i++)
	{
		if (_strcmp(args[0], builtins_cmd[i]) == 0)
			return ((*builtins_func[i])(args));
	}

	if (access(_strcat(args[0]), X_OK))
	{
		_print(args[0]);
		_print(": command not found\n");
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
		if (execve(_strcat(args[0]), args, NULL) == -1)
			_print("Error! Execution failed");
		exit(EXIT_FAILURE);
	}
	else
		wait(&status);

	return (1);
}
