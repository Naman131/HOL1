/*
============================================================================
Name : 16.c
Author : Naman Dave
Description : Write a program to perform mandatory locking. a. Implement write lock
b. Implement read lock
Date: August 25, 2024.
============================================================================
*/



#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/file.h>
#include<stdio.h>

int main(){
	struct flock lock;
	int fd;
	fd=open("db.txt",O_RDWR);
	lock.l_type=F_WRLCK;
	lock.l_whence=SEEK_SET; //start from start of file
	lock.l_start=0;
	lock.l_len=0;
	lock.l_pid=getpid();
	printf("Before entering CS\n");
	fcntl(fd,F_SETLKW,&lock);
	printf("Inside Critical Section\n");

	char* buff="Writing in buffer";
	write(fd,buff,sizeof(buff));
	sleep(30);
	printf("Enter to Unlock\n");
	getchar();
	printf("Unlocked\n");
	lock.l_type=F_UNLCK;
	fcntl(fd,F_SETLK,&lock);
	printf("finish\n");
}


//OUTPUT

/*
Before entering CS
Inside Critical Section
aman
Enter to Unlock
Unlocked
finish


*/
