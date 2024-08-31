/*
============================================================================
Name : 23.c
Author : Naman Dave
Description :  Write a program to create a Zombie state of the running program.
Date: August 25, 2024.
============================================================================
*/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
	pid_t pid=fork();
	
	if(pid<0){
		//fork failed
		perror("Fork failed");
		return 1;
	}

	else if(pid==0){
		//child process
		printf("The child process with pid =%d is exiting\n",getpid());
		exit(0); //child process exits
		//This make the child process a zombie since it has terminated but the parent hasn't called 'wait()' to clean up the process entry
	}	
	else{
		//parent process
		printf("parent process with pid =%d is sleping \n",getpid());
		sleep(30); //sleep for 30 secs to keep the parent alive
		printf("Parent process is exiting now\n");
	}
	return 0;
}


//OUTPUT
/*
parent process with pid =5210 is sleping 
The child process with pid =5211 is exiting
Parent process is exiting now
*/

//NOTE: We can also use ps aux | grep z command to get the current status of the zombie process
