/*
============================================================================
Name : 30.c
Author : Naman Dave
Description : Write a program to run a script at a specific time using a Daemon process.
Date: August 27, 2024.
============================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
	pid_t pid=fork();
	if(pid==-1){
		printf("fork failed\n");
		return 1;
	}
	
	if(pid==0){
		//child process
		sleep(10); //give some time for the parent process to exit
	
		printf("Creating a new session with setsid()\n");
		pid_t newSesh=setsid(); //create a new session

		if(newSesh==-1){
			//if setsid fails
			printf("Creating the new session failed\n");
			return 1;
		}
		else{
			//successfully created a new session
			printf("A new session created\n");
		}

		int changeDir= chdir("/"); //change the working directory to "/"

		if(changeDir==-1){
			//if chdir fails
			printf("trying to change the directory failed\n");
			return 1;
		}
		else{
			//successfully changed the directory
			printf("Changed the directory to '/'\n");
			
			while(1){
				sleep(2); //sleep for 2 secs
				printf("Process id of process is: %d\n",getpid()); //print process id
				printf("The daemon prcoess is running \n"); //indicates that the daemon is running
				
			}
		}
		}
		else{
			//parent process
			printf("Parent process: this is going to exit\n");
			exit(0); //parent process exits leaving the child process runnng
		}
	}

//OUTPUT
//Parent process: this is going to exit
/*
Creating a new session with setsid()
A new session created
Changed the directory to '/'
Process id of process is: 6711
The daemon prcoess is running 
Process id of process is: 6711
The daemon prcoess is running 
Process id of process is: 6711
The daemon prcoess is running 
Process id of process is: 6711
The daemon prcoess is running 
Process id of process is: 6711
The daemon prcoess is running 
*/
