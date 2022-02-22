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
		
		_strcat(paths[i], args, pathcmd);
		// printf("current path:%s\n", pathcmd);
		if (stat(pathcmd, &st) == 0)
		{
			printf("inside path check:\n");
			return (pathcmd);
		}
		// else
		// {
		// 	printf("inside else\n");
			// free(pathcmd);
		// }
		i++;
		
	}
	// printf("ennd..\n loop %d\n", i);
	// printf("path not found, returning command..\n");

	free(pathcmd);
	return (args);
}

