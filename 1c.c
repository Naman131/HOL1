/*
============================================================================
Name : 1c.c
Author : Naman Dave
Description : Create the following types of a files using 
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call)
Date: August 18, 2024.
============================================================================
*/




#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(){
	const char* path="/home/naman/SS/HandsOnList1/myFifo1";
	
	//create a fifo(named pipe)
	int result= mkfifo(path,0666);
	
	if(result==0){
		printf("Fifo file created successfully\n",path);
	}
	else{
		perror("Error creating fifo file");
	}
	return 0;
}

// using shell command we can do:
// mkfifo /home/naman/SS/HandsOnList1/myFifo2


//using mknod shell command to create FIFO file:
// mknod /home/naman/SS/HandsOnList1/myFifo


//OUTPUT
//Fifo file created successfully
