/*
============================================================================
Name : 26a.c
Author : Naman Dave
Description : Write a program to execute an executable program.
 a. use some executable program
Date: August 26, 2024.
============================================================================
*/



#include<stdio.h>
#include<stdlib.h>

int main(int argc,char* argv[]){
	if(argc<2){
		printf("usage %s \n",argv[0]);
		return 1;
	}

	printf("Hello %s\n",argv[1]);
	return 0;
}
 //we will now compile this program to create an executable named 26a
//i.e gcc -o 26a 26a.c
