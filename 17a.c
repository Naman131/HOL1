/*
============================================================================
Name : 17a.c
Author : Naman Dave
Description : Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to open the file, implement write lock, read the ticket number, increment the number and print the new ticket number then close the file.
Date: August 25, 2024.
============================================================================
*/


#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/file.h>
#include<stdio.h>

int main(){
	int ticketnumber=1;
	int fd= open("ticket_file.txt",O_WRONLY|O_CREAT|O_TRUNC,0644);
	if(fd==-1){
		perror("Failed to open the file");
		return 1;
	}
	else{
		printf("File opened successfully");
	}

	if(flock(fd,LOCK_EX) ==-1){ //checks exclusive lock
		perror("Failed to lock the file");
		return 1;
	}
	else{
		printf("Lock applied successfully\n");
	}
	write(fd,&ticketnumber,sizeof(ticketnumber));
	flock(fd,LOCK_UN);
	close(fd);
	
	printf("Ticket reservation successfull\n");
	return 0;
}


//OUTPUT
//File opened successfullyLock applied successfully
//Ticket reservation successfull
