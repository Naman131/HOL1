/*
============================================================================
Name : 20.c
Author : Naman Dave
Description : Find out the priority of your running program. Modify the priority with nice command.
Date: August 25,2024
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/resource.h>

int main(){
	int priority=10;//new priority value to be set
	
	//getting the current priority
	int oldPriority= getpriority(PRIO_PROCESS,0);
	printf("Old priority: %d\n",oldPriority);
	
	//Set the new priority
	if(setpriority(PRIO_PROCESS,0,priority)==-1){  //setpriority returns 0 when successful else -1
		perror("Set priority");
		return 1;
	}

	//get the updated prority
	int new_priority=nice(5);
	printf("New priority %d\n",new_priority);

	sleep(100);

	return 0;
}


//OUTPUT
/*
Old priority: 0
New priority 15
*/
