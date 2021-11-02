#include "header.h"



int (*builtins_func[])(char **) = {
	&env_func,
	&exit_func,
	&cd_func};

/**
 * env_func - prints all environment variables.
 * Return: 1
 */

int env_func(void)
{
	size_t i = 0;

	for (i = 0; environ[i] != NULL; i++)
	{
		_print(environ[i]);
		_print("\n");
	}
	return (1);
}

/**
 * exit_func - exits the shell.
 * Return: 0
 */

int exit_func(void)
{
	return (0);
}

/**
 * cd_func - changes directory
 * @args: array of strings
 * Return: out
 */
int cd_func(char **args)
{
	if (!args[1])
		return (1);
	if (chdir(args[1]) != 0)
		perror("no dir");
	return (1);
}

