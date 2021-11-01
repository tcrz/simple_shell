#include "header.h"
#include <stdio.h>

char **split_str(char *buf)
{
	char *token, **eachstr, *delim;
	int count = 0;

	delim = " \n";
	eachstr = malloc(sizeof(*eachstr) * 100);
	if (!eachstr)
		return (NULL);

	token = strtok(buf, delim);
	while (token)
	{
		eachstr[count] = token;
		token = strtok(NULL, delim);

		count++;
	}
	eachstr[count] = NULL;

	return (eachstr);
}

int main(int ac, char **av)
{
	unsigned int status = 1;
	char *userinput, **args;
	size_t userinput_size = 1000;
	int line;

	userinput = malloc(userinput_size);
	if (!userinput)
	{
		_print("Failed, can not allocate memory!");
		exit(EXIT_FAILURE);
	}

	while (status)
	{

		_print("($) ");
		line = getline(&userinput, &userinput_size, stdin);
		if (line == -1)
		{
			_putchar('\n');
			return (0);
		}
		args = split_str(userinput);
		status = execute(args);

		free(args);
	}
	free(userinput);

	return (0);
}
