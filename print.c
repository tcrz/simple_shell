#include "header.h"

void _print(char *str)
{
	write(STDOUT_FILENO, str, _strlen(str));
}
