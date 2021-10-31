#include "header.h"
extern char** environ;

void env()
{
        size_t i = 0;
        for (i = 0; environ[i] != NULL; i++)
        {
                _print(environ[i]);
                _print("\n");
        }
}
