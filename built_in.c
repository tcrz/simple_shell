#include "header.h"



int (*builtins_func[])(char **) = {
	&env_func,
	&exit_func,
	&cd_func};

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

int exit_func(void)
{
	return (0);
}

int cd_func(char **args)
{
	if (!args[1])
		return (1);
	if (chdir(args[1]) != 0)
		perror("no dir");
	return (1);
}

