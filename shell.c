#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main ()
{
        size_t n = 100;
        char *buf, *str;
        char *delim = " ";
        int fl;

         buf = malloc(sizeof(char) * n);
        if (!buf)
                return (0);

        printf("($) ");

        /* read a line */
        fl = getline(&buf, &n, stdin);
        if (fl < 0)
        {
                perror("yawa dey");
                exit(EXIT_FAILURE);
        }

        /* split strings */
        str = strtok(buf, delim);
        if(!str)
        {
                printf("%s..couldnt split\n", buf);
                return (0);
        }
        while(str)
        {
                printf("%s\n", str);
                str = strtok(NULL, delim);

        }
}

