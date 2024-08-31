/*
============================================================================
Name : 5.c
Author : Naman Dave
Description : Write a program to create five new files with infinite loop. Execute the program in the background and check the file descriptor table at /proc/pid/fd.
Date: August 19, 2024.
============================================================================
*/



#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	//array to hold the file descriptors
	int fds[5];
	const char* nameOfFiles[5]={"File1.txt","File2.txt","File3.txt","File4.txt","File5.txt"};
	
	printf("Process id is:%d\n",getpid());
	//create five new files
	for(int i=0;i<5;i++){
		fds[i]=open(nameOfFiles[i],O_CREAT | O_RDWR, 0644); //open in read -write mode if file exist else first create it and open with permission 0644
		if(fds[i]<0){
			perror("Error creating file");
			return 1;
		}
		else{
			printf("Created %s file with fd value: %d\n",nameOfFiles[i],fds[i]);
		}
		
	}

	//infinite loop to keep the program running
	while(1){
		sleep(10); //sleep for 10 seconds to avoid consuming too much CPU
	}

	//close the files(this wont be reached due to the infinite loop)
	for(int i=0;i<5;i++){
		close(fds[i]);
	}
	return 0;
}


//We used the pid to get inside the proc directory using the -> cd /proc/Pid command
//then we did ls -l fd to view info of the fds

//OUTPUT

//total 0
//lrwx------ 1 naman naman 64 Aug 22 12:16 0 -> /dev/pts/0
//lrwx------ 1 naman naman 64 Aug 22 12:16 1 -> /dev/pts/0
//lrwx------ 1 naman naman 64 Aug 22 12:16 2 -> /dev/pts/0
//lrwx------ 1 naman naman 64 Aug 22 12:16 3 -> /home/naman/SS/HandsOnList1/File1.txt
//lrwx------ 1 naman naman 64 Aug 22 12:16 4 -> /home/naman/SS/HandsOnList1/File2.txt
//lrwx------ 1 naman naman 64 Aug 22 12:16 5 -> /home/naman/SS/HandsOnList1/File3.txt
//lrwx------ 1 naman naman 64 Aug 22 12:16 6 -> /home/naman/SS/HandsOnList1/File4.txt
//lrwx------ 1 naman naman 64 Aug 22 12:16 7 -> /home/naman/SS/HandsOnList1/File5.txt
