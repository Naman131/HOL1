/*
============================================================================
Name : 2.c
Author : Naman Dave
Description : Write a simple program to execute in an infinite loop at the background. Go to /proc directory and identify all the process related information in the corresponding proc directory.
Date: August 18, 2024.
============================================================================
*/



#include<stdio.h>
#include<unistd.h>

int main(){
	while(1){
	//Print the process ID and sleep for 5 seconds
	printf("Process ID is %d\n", getpid());
	sleep(5);  //the program will print process id every 5 seconds and run indefinitely
}
return 0;
}


//to run the program in the background -> ./a.out &

//after identifying the process id, in another instance of the terminal write-> cd /proc/pid
//after entering the proc directory we can view process info by -> cat stat, ls -l fd/ (directory containing sybolic links to process's open file descriptors

//at end-> kill pid



//OUTPUT

/*
Process ID is 4741
..
..
*/
