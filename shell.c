#include "header.h"

void welcome()
{
	_print("($) ");
}
void get_cmd(char **cmd)
{
	size_t r = 1000;
	getline(cmd, &r, stdin);
}
int main(void)
{
	unsigned int status = 1;
	char *cmd;
	
	cmd = malloc(sizeof(char) * 1000);
	while(status)
	{
		welcome();
		get_cmd(&cmd);
		_print(cmd);
		if(_strcmp(cmd, "exit") == 0)
			status = 0;
	}
	free(cmd);
	return (0);
}
