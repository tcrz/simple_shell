#include "header.h"

/* void line_input(char **userinput)
{
	size_t r = 1000;

	getline(userinput, &r, stdin);
} */

char **split_str(char *buf)
{
	char *token, **eachstr, *delim;
	int count = 0;

	/*if(buf[0] == '\n' || buf[0] == ' ')
	delim = "";
	else */
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

	userinput = malloc(userinput_size);
	if (!userinput)
	{
		perror("cant allocate memory");
		exit(EXIT_FAILURE);
	}

	while (status)
	{

		_print("($) ");
		getline(&userinput, &userinput_size, stdin);
		args = split_str(userinput);

		if (!args[0])
			args[0] = "";
		else if (_strcmp(args[0], "exit") == 0)
			status = 0;
		else
			execute(args);
	}
	free(userinput);
	free(args);
	return (0);
}
