#include "header.h"

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
		if (execve(args[0], args, NULL) == -1)
			perror("error!");
		exit(EXIT_FAILURE);
	}
	else
		wait(&status);

}


void get_cmd(char **cmd)
{
	size_t r = 1000;

	getline(cmd, &r, stdin);
}

char **split_cmd(char *buf)
{
	char *token, **eachstr, *delim = " \n";
	int count = 0;

	eachstr = malloc(sizeof(char) * 100);
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
	char *cmd, **args;

	cmd = malloc(sizeof(char) * 1000);
	if (!cmd)
	{
		perror("cant allocate memory");
		exit(EXIT_FAILURE);
	}

	while (status)
	{
		int i = 0;

		_print("($) ");
		get_cmd(&cmd);
		args = split_cmd(cmd);

		if (_strcmp(args[0], "exit") == 0)
			status = 0;
		execute(args);
	}
	free(cmd);
	free(args);
	return (0);
}
