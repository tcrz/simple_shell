#include "header.h"

void get_cmd(char **cmd)
{
	size_t r = 1000;
	getline(cmd, &r, stdin);
}

char** split_cmd(char *buf)
{
	char *token, **eachstr, *delim = " ";
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

	return eachstr;

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

	while(status)
	{
		int i = 0;
		_print("($) ");
		get_cmd(&cmd);
		args = split_cmd(cmd);

		/*prints each arg on new line */
		while (args[i])
		{
			 _print(args[i]);
			_print("\n");
			i++;
		}

		if(_strcmp(args[0], "exit") == 0)
			status = 0;
	}
	free(cmd);
	free(args);
	return (0);
}
