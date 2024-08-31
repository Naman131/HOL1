/*
============================================================================
Name : 25.c
Author : Naman Dave
Description : Write a program to create three child processes. The parent should wait for a particular child (use waitpid system call)
Date: August 26, 2024.
============================================================================
*/

#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/resource.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
    int status;
    pid_t pid1, pid2, pid3;

    // First child process
    pid1 = fork();
    if (pid1== -1) {
        printf("Fork failed for pid1\n");
        exit(1);
    } else if (pid1 == 0) {
        // Child process 1
        printf("Child process 1 (PID: %d)\n", getpid());
        exit(0);  // Child exits
    }

    // Second child process
    pid2 = fork();
    if (pid2 == -1) {
        printf("Fork failed for pid2\n");
        exit(1);
    } else if (pid2 == 0) {
        // Child process 2
        sleep(10);  // Sleep for 10 seconds to simulate work
        printf("Child process 2 (PID: %d)\n", getpid());
        exit(0);  // Child exits
    }

    // Third child process
    pid3 = fork();
    if (pid3 == -1) {
        printf("Fork failed for pid3\n");
        exit(1);
    } else if (pid3 == 0) {
        // Child process 3
        printf("Child process 3 (PID: %d)\n", getpid());
        exit(0);  // Child exits
    }

    // Parent process: wait for the specific child process (pid2) to exit
    printf("Parent (PID: %d) waiting for PID %d to finish...\n", getpid(), pid2);
    pid_t waited_pid = waitpid(pid2, &status, 0); //waitpid() suspends the calling process until the system gets info on the child

    if (waited_pid == -1) {
        perror("waitpid error");
    } else {
        if (WIFEXITED(status)) {
            printf("Parent: Child with PID %d exited with status %d\n", waited_pid, WEXITSTATUS(status));
        } else {
            printf("Parent: Child with PID %d did not exit normally\n", waited_pid);
        }
    }

    return 0;
}


//OUTPUT
/*
Parent (PID: 6266) waiting for PID 6268 to finish...
Child process 1 (PID: 6267)
Child process 3 (PID: 6269)

Child process 2 (PID: 6268)
Parent: Child with PID 6268 exited with status 0
*/
