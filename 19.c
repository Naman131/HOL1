/*
============================================================================
Name : 19.c
Author : Naman Dave
Description :  Write a program to find out time taken to execute getpid system call. Use time stamp counter
Date: August 25, 2024.
============================================================================
*/




#include<stdio.h>
#include<unistd.h>
#include<stdint.h>

//function to read the time stamp counter

unsigned long long readTimeStamp(){
	unsigned int s,e;
	__asm__ volatile("rdtsc": "=a"(s), "=d"(e));
	return ((unsigned long long)e<<32) | s; 
}

int main(){
	unsigned long long s,e;
	pid_t pid;

	//measure the time before and after the getpid() call

	s= readTimeStamp();
	pid=getpid();
	e= readTimeStamp();
	
	printf("Process ID%d\n", pid);
	printf("Time taken to get the pid in clock cycle %llu\n",e-s); //llu->long long unsigned int

	return 0;
}


//OUTPUT

/*
Process ID3772
Time taken to get the pid in clock cycle 26870
*/
