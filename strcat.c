#include "header.h"

/**
* _strcat - concatenatates strings
* @dest: string to be added to.
* @src: string to be added
* @fullstr: stores concatenated string
* Return: concatenated string
*/

char *_strcat(char *dest, char *src, char *fullstr)
{
	int x, y;

	for (x = 0; dest[x] != '\0'; x++)
		fullstr[x] = dest[x];

	fullstr[x] = '/';
	x++;

	for (y = 0; src[y] != '\0'; y++)
		fullstr[x + y] = src[y];

	fullstr[x + y] = '\0';

	return (fullstr);
}


