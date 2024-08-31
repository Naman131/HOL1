/*
============================================================================
Name : 24.c
Author : Naman Dave
Description : Write a program to create an orphan process.
Date: August 25, 2024.
============================================================================
*/


#include <stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<sys/resource.h>
#include<stdlib.h>

int main(){
	pid_t pid=fork();
	
	if(pid<0){
		//fork has failed
		perror("Fork failed");
		return 1;
	}

	else if(pid==0){
		//child process
		sleep(5); //this is done in order to ensure that the parent terminates first
		printf("Child process is now orphan and its pid is: %d\n",getpid()); // when a child process becomes orphan it is adopted by init process which becomes its new parent
		printf("New parent for child is init and its pid is %d\n", getppid());
	}
	else{
		//parent process
		printf("The parent process is terminating and its pid is: %d\n",getpid());
		exit(0); //parent process exits making the chile orphan
	}
	return 0;
}

//OUTPUT
/*
The parent process is terminating and its pid is: 5500
Child process is now orphan and its pid is: 5501
New parent for child is init and its pid is 1554
*/
