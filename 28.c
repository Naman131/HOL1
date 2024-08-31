/*
============================================================================
Name : 28.c
Author : Naman Dave
Description :Write a program to get maximum and minimum real time priority.

Date: August 27, 2024.
============================================================================
*/

#include<stdio.h>
#include<sched.h>

int main(){
	int maxPr_fifo;
	int minPr_fifo;
	int maxPr_RR;
	int minPr_RR;
	
	//max and min priority for FIFO scheduling
	maxPr_fifo= sched_get_priority_max(SCHED_FIFO);
	minPr_fifo= sched_get_priority_min(SCHED_FIFO);

	//max and min priority for RR scheduling
	maxPr_RR= sched_get_priority_max(SCHED_RR);
	minPr_RR= sched_get_priority_min(SCHED_RR);

	printf("for FIFO max priority=%d , Min Priority=%d \n", maxPr_fifo,minPr_fifo);
	printf("for RR max Priority= %d , Min priority=%d \n", maxPr_RR, minPr_RR);

	return 0;
}


//OUTPUT
/*
for FIFO max priority=99 , Min Priority=1 
for RR max Priority= 99 , Min priority=1 
*/
