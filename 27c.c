/*
============================================================================
Name : 27c.c
Author : Naman Dave
Description : Write a program to execute ls -Rl by the following system calls a. execl
b. execlp
c. execle
d. execv 
e. execvp
Date: August 27, 2024.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>

int main(){
        //using execv 
        printf("Executing ls -Rl using execv\n");
        char* args[]={"ls","-Rl",NULL};
        execv("./27ex2",args);
        perror("execv failed");
        return 1;
}
