#include "header.h"

/**
* _strcat - compares two strings
* @str: first string
* Return: returns concatenated string value
*/

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
