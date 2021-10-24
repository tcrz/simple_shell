#include "header.h"
int _strcmp(char *str, char *strcom)
{
	int i = 0;
	_print(str);
	for(; str[i] || strcom[i]; i++)
	{
		if(str[i] != strcom[i])
			return (1);
	}
	return (0);
}
