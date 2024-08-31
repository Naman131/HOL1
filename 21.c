/*
============================================================================
Name : 21.c
Author : Naman Dave
Description : Write a program, call fork and print the parent and child process id.
Date: August 25, 2024.
============================================================================
*/


#include<unistd.h>
#include<stdio.h>
#include<sys/resource.h>

int main(){
	pid_t pid;
	//create a new process
	pid=fork();

	if(pid<0){
		//this means fork failed
		perror("Fork Failed");
		return 1;
	}

	else if(pid==0){
		//means this is child proccess
		printf("This is child process and its pid =%d\n",getpid());
		printf("Parent PID(from child) is: %d\n",getppid());
	}

	else{
		//if we are in this block it means it is parent process
		printf("This is parent process and the process ID is: %d\n",getpid());
		printf("child pid(from parent) is: %d\n",pid);
	}

	return 0;
}


//OUTPUT

/*
This is parent process and the process ID is: 4881
child pid(from parent) is: 4882
This is child process and its pid =4882
Parent PID(from child) is: 1554
*/
