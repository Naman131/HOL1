/*
============================================================================
Name : 7.c
Author : Naman Dave
Description : Write a program to copy file1 into file2 ($cp file1 file2).
Date: August 19, 2024.
============================================================================
*/



#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

#define bufferSize 1024

int main(int argc,char* argv[]){
	if(argc!=3){
	//check if correct no. of arguments is provided
		printf("Usage %s <sourceFile> <destFile>\n",argv[0]);
		return 1;
	}
	
	//Open the source file for reading
	int source_fd= open(argv[1],O_RDONLY);
	if(source_fd<0){
		perror("Error opening source file");
		return 1;
	}
	
	//open/create the dest file for wrting
	int dest_fd= open(argv[2],O_WRONLY | O_CREAT | O_TRUNC,0644);
	if(dest_fd<0){
		perror("Error opening/creating the destination file");
		close(source_fd);
		return 1;
	}

	//buffer to store the file content
	char buffer[bufferSize];
	int bytesRead,bytesWritten;
	
	//read from source file and write to dest file
	while((bytesRead=read(source_fd,buffer,bufferSize))>0){
		bytesWritten=write(dest_fd,buffer,bytesRead);
		if(bytesWritten!=bytesRead){
			perror("Error writing to dest file");
			close(source_fd);
			close(dest_fd);	
			return 1;
		}
	}
	if(bytesRead<0){
		perror("error reading from source file");
		
	}
	
	//close the fds
	close(source_fd);
	close(dest_fd);

	printf("File copied Scuccessfully \n");
	return 0;
	
}


//OUTPUT
//File copied successfully
