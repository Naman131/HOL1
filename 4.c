/*
============================================================================
Name : 4.c
Author : Naman Dave
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: August 18, 2024.
============================================================================
*/



#include<stdio.h>
#include<fcntl.h> //for open,O_RDWR,O_EXCL
#include<unistd.h> // for close

int main(){
	//open an existing file with read and write permissions
	int fd= open("ExampleForQues3.txt",O_RDWR);
	
	if(fd<0){
		perror("Error opening file");
		return 1;
	}
	printf("File opened successfully in read-write mode and fd value is %d\n",fd);
	
	//Now opening the file with O_EXCL flag
	int ed= open("ExampleForQues3.txt",O_RDWR | O_EXCL);
	if(ed<0){
		perror("Error opening the file with O_EXCL");
	}
	else{
		printf("File opened successfully with O_EXCL flag with fd=%d\n",ed);
		close(ed);
	}
	//close the original fd
	close(fd);
	return 0;

}



//OUTPUT:
//File opened successfully in read-write mode and fd value is 3
//File opened successfully with O_EXCL flag with fd=4

