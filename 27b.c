/*
============================================================================
Name : 27b.c
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
       //using execlp
        printf("executing ls -Rl using execlp\n");
        execlp("ls","ls","-Rl",NULL);
        perror("execlp failed");
        return 1;

        return 0;
}
