/*
============================================================================
Name : 10.c
Author : Naman Dave
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10 bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.
Date: August 22, 2024.
============================================================================
*/


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include <string.h>

int main(){
	int fd= open("q7ex2.txt", O_RDWR |O_CREAT | O_TRUNC,0666);
	if(fd==-1){
		perror("Error in opening file");
		return 1;
	}

	//taking the first 10 bytes
	
	const char* d1="1234567890";
	int bytesWritten= write(fd,d1,strlen(d1));
	if(bytesWritten!= strlen(d1)){
		perror("Error writing first 10 bytes");
		close(fd);
		return 1;
	}
	long int index= lseek(fd,10,SEEK_CUR); // move current seek forward by 10 bytes
	if(index==-1){
		perror("Error seekin");
		close(fd);
		return 1;
	}

	const char* d2="Naman Dave";
	bytesWritten= write(fd,d2,strlen(d2));
	if(bytesWritten==-1){
		perror("Error Writing");
		close(fd);
		return 1;
	}

	close(fd);
	printf("lseek returned index: %ld\n",index);
	return 0;
}

//OUTPUT

//lseek returned index: 20
