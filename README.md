# SIMPLE SHELL #
This project is a simple version of the linux shell. Simple Shell is a simple program which takes the keyboard commands and delivers them to the system to be executed. It also verifies if the command inputs from the user are correct. This project contains functionalities of shell such as : Handling PATHS, implementing BUILT-INS and executing commands. This shell is developed in the programming language C.

## DESCRIPTION ##
## Essential Functionalities of the Simple Shell:
> Displays a prompt "#($)" and waits for user input.\
> Runs all commands of type "executable program" (ls and /bin/ls).\
> Runs the following build_in commands: **exit**, **env**, **cd**\
> Handles commands with arguments.\
> Handles the PATH global variable.\
> Handles The EOF (End Of File) condition.\
> Handles the Ctrl + C signal -> It doesn't exit the shell  
> Shell can be exited by executing **exit** or Ctrl + D

## USAGE
You can try our shell by following these steps:
> **Step 1:** Clone our repository using this command, (you need to have git installed on your machine first)
````
git clone https://github.com/tcrz/simple_shell
````
> **Step 2:** Change directory to simple_shell:
````
cd simple_shell
````
> **Step 3:** Compile the C files in this way:
````
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
````
> **Step 4:** Run the shell
````
./hsh
````
**Exiting the shell**
When you want to exit the shell, you can use one of the following methods:
- 1: Type the command "exit"
````
exit
````
- 2: Press on Ctrl + D

## Example of Usage
```
($) pwd
/home/crzctrl/ALX-SE/simple_shell
($) ls
AUTHORS  README.md  built_in.c	exec.c  header.h	hsh  paths_func.c  print.c  putchar.c shell.c  strcat.c  strcmp.c  strlen.c
($) cat AUTHORS
# simple shell project contributors

Tony baidoo <crzctrl5789@gmail.com>
Fitsum Belay <fitsum.ozo@gmail.com>
($) exit
crzctrl@tonycrz-Aspire-V5-123:~/ALX-SE/simple_shell$ 
```

## TEAM
The simple shell project is a collaboration by [Tony Baidoo](https://github.com/tcrz) and [Fitsum Belay](https://github.com/f-i-t-s-u-m)
