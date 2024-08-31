/*
============================================================================
Name : 13.c
Author : Naman Dave
Description : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: August 22, 2024.
============================================================================
*/



#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/time.h>
#include<sys/types.h>

int main(){
	// fd set
	fd_set rfds;
	//making a timeout structure
	struct timeval tv;
	
	//clear the set and add STDIN to the set
	FD_ZERO(&rfds);
	FD_SET(0,&rfds); //fd of STDIN is 0
	
	//setting the timeout to 10 secs
	tv.tv_sec=10;
	tv.tv_usec=0;
	
	printf("Waiting for input\n");
	
	//wait for input on STDIN
	int retval;
	retval= select(1, &rfds,NULL,NULL,&tv); //select allows a program to monitor multiple fds waiting until 1 or more fds become ready for some I/O operation
	if(retval==-1){
		perror("select()");
	}
	else if(retval){
		printf("Data is available as input\n");
	}
	else{
		printf("No data was entered in 10 secs\n");// if retval==0
	}

return 0;
}

//OUTPUT
/*
Waiting for input
Naman
Data is available as input
*/
