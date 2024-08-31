/*
============================================================================
Name : 27.c
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
	//first we created an executable file called 27ex.c

	//Using execl
	printf("Executing ls -Rl using execl\n");
	execl("./27ex","ls","-Rl",NULL);
	perror("execl failed"); //will be printed if execl fails
	return 1;

	return 0;
}
