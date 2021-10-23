#include "header.h"

void welcome()
{
	_printf("($) ");
}
void get_cmd(char *cmd)
{
	int r = 100;
	read(STDIN_FILENO, cmd, r);
}
int main(void)
{
	unsigned int status = 1;
	char cmd[100];

	while(status)
	{
		welcome();
		get_cmd(cmd);
		_printf(cmd);
		
		if(cmd == "EXIT")
			return (0);
	}
return (0);
}
