/*
============================================================================
Name : 1b.c
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

	const char *targetName="/home/naman/SS/HandsOnList1/ex2";
	const char *linkingFrom="/home/naman/SS/HandsOnList1/link2.txt";
	
	int result=link(targetName,linkingFrom);
	
	if(result==0){
		printf("HardLink created successfully\n");
	}
	else{
		perror("Error");
	}
	return 0;
}

//OUTPUT
//HardLink created successfully
