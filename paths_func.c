#include "header.h"

/**
* getpath - returns all environment paths
* Return: an array of environment paths
*/
char **getpath(void)
{
	char *pathstr, *token, **eachpath, *delim = ":";
	int count = 0;

	pathstr = getenv("PATH");
	eachpath = malloc(sizeof(*eachpath) * 100);
	token = strtok(pathstr, delim);
	while (token)
	{
		eachpath[count] = token;
		token = strtok(NULL, delim);
		count++;
	}
	eachpath[count] = NULL;
	return (eachpath);
}

/**
* checkforpath - checks if command exists and returns
* the full path of the command
* @cmd: command to find path of
* @paths: array of all environment paths
* Return: full path of the command if found else the command
*/

char *checkforpath(char *cmd, char **paths)
{
	struct stat st;
	int i = 0;
	char *fullcmdpath = malloc(50);

	while (paths[i] != NULL)
	{
		_strcat(paths[i], cmd, fullcmdpath);
		if (stat(fullcmdpath, &st) == 0)
			return (fullcmdpath);
		i++;
	}
	free(fullcmdpath);
	return (cmd);
}
