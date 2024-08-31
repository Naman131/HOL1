/*
============================================================================
Name : 14.c
Author : Naman Dave
Description : Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.
Date: August 24, 2024.
============================================================================
*/


#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>

void solve(struct stat filestat){
	if(S_ISREG(filestat.st_mode)){
		printf("Regular file\n");
	}
	else if(S_ISDIR(filestat.st_mode)){
		printf("Directory\n");
	}
	else if(S_ISCHR(filestat.st_mode)){
		printf("Character device\n");
	}
	else if(S_ISBLK(filestat.st_mode)){
		printf("Block device\n");
	}
	else if(S_ISFIFO(filestat.st_mode)){
		printf("FIFO file\n");
	}
	else if(S_ISLNK(filestat.st_mode)){
		printf("Sybolic link\n");
	}
	else if(S_ISSOCK(filestat.st_mode)){
		printf("Socket\n");
	}
	else{
		printf("Unknown file type\n");
	}
}


int main(int argc, char* argv[]){
	if(argc!=2){
		printf("specify file name: %s\n",argv[0]);
		return 1;
	}
	
	struct stat filestat;
	
	//getting the file status
	if(stat(argv[1], &filestat)<0){
		printf("Error in getting file info");
		return 1;
	}
	
	//else print the type of file
	solve(filestat);
	return 0;
}

//OUTPUT
//./a.out q7ex2.txt
//Regular file

