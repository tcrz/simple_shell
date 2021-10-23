#include "header.h"
void _printf(char *str)
{
	write(STDOUT_FILENO, str, _strlen(str));
}
