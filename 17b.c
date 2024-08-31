/*
============================================================================
Name : 17b.c
Author : Naman Dave
Description : Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to open the file, implement write lock, read the ticket number, increment the number and print the new ticket number then close the file.
Date: August 25, 2024.
============================================================================
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/file.h>

int main(){
	int ticketnumber;
	int fd= open("ticket_file.txt",O_RDWR);
	if(fd==-1){
		perror("Failed to open the file");
		return 1;
	}
	else{
		printf("File opened successfully\n");
	}
	
	if(flock(fd,LOCK_EX) == -1){
		perror("Failed to lock the file");
		return 1;
	}
	else{
		printf("Lock applied successfully\n");
	}

	read(fd, &ticketnumber,sizeof(ticketnumber));
	ticketnumber++;
	lseek(fd,0,SEEK_SET);
	write(fd,&ticketnumber,sizeof(ticketnumber));
	flock(fd,LOCK_UN);
	close(fd);
	printf("The new ticket number is: %d\n",ticketnumber);
	return 0;
}

//OUTPUT
/*
File opened successfully
Lock applied successfully
The new ticket number is: 2
*/
