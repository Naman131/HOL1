/*
============================================================================
Name : 11.c
Author : Naman Dave
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl
Date: August 22, 2024.
============================================================================
*/


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

void appendUsingFD(int fd,const char* text){
	if(write(fd,text,strlen(text)) !=strlen(text)){
		perror("error writing to file");
	}
}

int main(int argc,char* argv[]){
	if(argc!=2){
		printf("Usage %s ques7ex2.txt\n",argv[0]);
		return 1;
	}

	//open the file in append mode
	int fd= open(argv[1],O_WRONLY | O_APPEND);
	if(fd<0){
		perror("Error opening file");
		return 1;
	}
	
	//duplicating the fd using dup command
	int fd_dup= dup(fd);
	if(fd_dup<0){
		perror("Error duplicating fd using dup()");
		close(fd);
		return 1;
	}

	//duplicating the fd usin dup2
	int fd_dup2=dup2(fd,48); //duplicates the fd as 48
	if(fd_dup2<0){
		perror("Error duplicating this file using dup2()");
		close(fd);
		close(fd_dup);
		return 1;
	}

	//duplicating the fd using fcntl command
	int fd_fcntl=fcntl(fd,F_DUPFD,200); //duplicates fd starting as 100
	if(fd_fcntl<0){
		perror("Error duplicating fd using fcntl");
		close(fd);
		close(fd_dup);
		close(fd_dup2);
		return 1;
	}

	
	//append using original fd
	appendUsingFD(fd,"Appended using original fd\n");
	appendUsingFD(fd_dup,"Appended using dup() fd\n");
	appendUsingFD(fd_dup2,"Appended using dup2() fd\n");
	appendUsingFD(fd_fcntl,"Appended using fcntl fd\n");
	
	//close all the fd
	close(fd);
	close(fd_dup);
	close(fd_dup2);
	close(fd_fcntl);

	printf("File has been updated\n");
	return 0;


}


//OUTPUT
//File has been updated

//OUTPUT q7ex2.txt
/*
Appended using original fd
Appended using dup() fd
Appended using dup2() fd
Appended using fcntl fd
*/
