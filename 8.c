/*
============================================================================
Name : 8.c
Author : Naman Dave
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read. Close the file when end of file is reached.
Date: August 22, 2024.
============================================================================
*/



#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

#define bufferSize 1024

int main(int argc,char* argv[]){
	if(argc!=2){
		//check if correct no. of arguments is provided
		printf("Use: %s q7ex2.txt",argv[0]);
		return 1;
	}
	
	//open the file in read only mode
	int fd= open(argv[1],O_RDONLY);
	if(fd<0){
		perror("Error opening file");
		return 1;
	}
	
	char buffer[bufferSize];
	int bytesRead;
	int i;
	
	//read the file  line by line
	while((bytesRead=read(fd,buffer,bufferSize))>0){
		for(i=0;i<bytesRead;i++){
			//print each character
			putchar(buffer[i]);

			//print a new line if we encounter one
			if(buffer[i]=='\n'){
				fflush(stdout); //flush the output buffer to ensure immediate output
			}
		}
	}

	if(bytesRead<0){
	perror("Error reading file");
	
}

	//close the fd
	close(fd);

	return 0;
}


//OUTPUT
//1234567890Naman DaveAppended using original fd

