#include "header.h"
char *_strcat(char *dest, char *src, char *fullpath)
{
	int x, y;

	for (x = 0; dest[x] != '\0'; x++)
		fullpath[x] = dest[x];

	fullpath[x] = '/';
	x++;

	for (y = 0; src[y] != '\0'; y++)
		fullpath[x + y] = src[y];

	fullpath[x + y] = '\0';

	return (fullpath);
}

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

char *checkforpath(char *args, char **paths)
{

	struct stat st;
	int i = 0;
	char *pathcmd = malloc(50);
	while (paths[i] != NULL)
	{
		printf("loop %d\n", i);
		printf("checking..\n");
		_strcat(paths[i], args, pathcmd);
		printf("current path:%s\n", pathcmd);
		if (stat(pathcmd, &st) == 0)
		{
			printf("inside path check :");
			return (pathcmd);
		}
		// else
		// {
		// 	printf("inside else\n");
		// 	// free(pathcmd);
		// }
		i++;
		
	}
	// printf("ennd..\n loop %d\n", i);
	printf("path not found, returning command..\n");

	// free(pathcmd);
	return (args);
}

/**
* _strcat - compares two strings
* @str: first string
* Return: returns concatenated string value
*/
/*
char *_strcat(char *str)
{
	int i = 0, n = 0;
	char *path = "/bin/";
	char *buf;

	if (_strncmp(str, "/", 1) == 0)
		return (str);

	buf = malloc(sizeof(char) * (_strlen(str) + _strlen(path) + 1));
	if (buf == NULL)
		return (NULL);

	while (i < _strlen(path))
	{
		buf[i] = path[i];
		i++;
	}
	while (n <= _strlen(str))
	{
		buf[i] = str[n];
		i++;
		n++;
	}
	return (buf);
}
*/
