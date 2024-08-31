/*
============================================================================
Name : 22.c
Author : Naman Dave
Description :  Write a program, open a file, call fork, and then write to the file by both the child as well as the parent processes. Check output of the file
Date: August 25, 2024.
============================================================================
*/


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>

int main(){
	int fd;
	
	//open the file in write only mode and with append flag
	fd= open("q7ex2.txt", O_WRONLY |O_APPEND);
	if(fd<0){
		perror("error opening the file");
		return 1;
	}

	//creating a new process 
	int newProcess= fork();
	
	if(newProcess==0){
		//means this is child process
		char* childWrite= "Child is writing\n";
		write(fd,childWrite, strlen(childWrite));   //NOTE: Here we dont require any lseek since the file is O_APPEND flag ,the file ptr automatically moves to the end of filebefore each write operation
		printf("Child has written\n");
	}

	else{
		//parent process
		char* parentWrite="parent is writing\n";
		write(fd,parentWrite,strlen(parentWrite));
		printf("Parent has written \n");
	}

	close(fd);
	return 0;
}


//OUTPUT IN TERMINAL
/*
Parent has written 
Child has written
*/



//OUTPUT IN FILE
/*
parent is writing
Child is writing
*/
