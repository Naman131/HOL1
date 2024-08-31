/*
============================================================================
Name : 3.c
Author : Naman Dave
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call
Date: August 18, 2024.
============================================================================
*/


#include<stdio.h>
#include<fcntl.h> //for  open ,creat
#include<unistd.h> //for close

int main(){
	//use creat() system call to creat a new file or trunate or existing file
	int fd=creat("ExampleForQues3.txt",0644);
	
	if(fd<0){
		//if fd is negative ,an error occured
		perror("Error creating file");
		return 1;
}

	//print the fd value
	printf("File created successfully and its value is %d\n",fd);
	
	//close the file
	close(fd);
	return 0;
}


//OUTPUT:
//  FIle Created Succesfully and its value is 3
