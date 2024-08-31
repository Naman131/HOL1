/*
============================================================================
Name : 26b.c
Author : Naman Dave
Description : Write a program to execute an executable program.
 b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date: August 26, 2024.
============================================================================
*/


#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

int main(){
	//specify the path to the executable program
	char* path= "./26a";
	
	//pass the arguments to the 26a 
	char* args[]={path, "Naman",NULL};
	
	//executing the program with the given arguments
	printf("Executing %s with input \n",path);
	execv(path,args);//execute the program 26a with argv getting the arguments from args

	//if execv returns it means it has failed
	perror("execv failed");
	return 1;
 
}


//OUTPUT
/*
Executing ./26a with input 
Hello Naman
*/
