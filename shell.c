#include "header.h"

extern char** environ;

void env()
{
	size_t i = 0;
	for (i = 0; environ[i] != NULL; i++)
	{
		_print(environ[i]);
		_print("\n");
	}
}

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

int main(void)
{
	unsigned int status = 1;
	char *userinput, **args;
	size_t userinput_size = 1000;
	int line;

	userinput = malloc(userinput_size);
	if (!userinput)
	{
		perror("cant allocate memory");
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
		if (!args[0])
			args[0] = "";
		else if (_strcmp(args[0], "exit") == 0)
			status = 0;
		else if (_strcmp(args[0], "env") == 0)
                        env();
		else
			execute(args);

		free(args);
	}
	free(userinput);

	return (0);
}
