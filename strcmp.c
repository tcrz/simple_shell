#include "header.h"


int _strcmp(char *str, char *strcom)
{
	int i = 0;

	while (str[i] != '\0' && strcom[i] != '\0')
	{
		if (str[i] != strcom[i])
			return (1);
		i++;
	}
	return (0);
}
