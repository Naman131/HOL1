/*
============================================================================
Name : 1a.c
Author : Naman Dave
Description : Create the following types of a files using 
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call)
Date: August 18, 2024.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>

int main(){
	
	const char *targetFile= "/home/naman/SS/HandsOnList1/ex1.txt";
	const char *linkingName= "/home/naman/SS/HandsOnList1/link1.txt";
	
	//creating the symbolic link
	if(symlink(targetFile,linkingName)==0){
		printf("Soft link created successfully\n");
	}
	else{
		perror("symLink");
	}
return 0;

}

//OUTPUT
//Soft link created successfully
