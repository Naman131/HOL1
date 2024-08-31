/*
============================================================================
Name : 27d.c
Author : Naman Dave
Description : Write a program to execute ls -Rl by the following system calls a. execl
b. execlp
c. execle
d. execv 
e. execvp
Date: August 27, 2024.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>

int main(){
	printf("Executing ls -Rl using execvp\n");
	char* args[]={"ls","-Rl",NULL};
	execvp("ls",args);
	perror("execvp failed");
	return 1;
}
