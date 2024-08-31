/*
============================================================================
Name : 9.c
Author : Naman Dave
Description :  Write a program to print the following information about a given file. 
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification j. time of last change
Date: August 22, 2024.
============================================================================
*/

#include<sys/types.h>
#include<sys/stat.h>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc,char* argv[]){
	struct stat sb;
	if(argc!=2){
		printf("Usage: %s <pathname>\n",argv[0]);
		exit(EXIT_FAILURE);
	}

	if(stat(argv[1],&sb)==-1){  //checking whether the sb structure has been filled with file info or not
		perror("Stat");
		exit(EXIT_FAILURE);	
	}

	//printing all the file info
	printf("File Type is %s\n",argv[1]);
	printf("a. inode : %ld\n", (long)sb.st_ino);
	printf("b. Number of hardlinks %ld\n", (long) sb.st_nlink);
	printf("c. UID= %ld \n",(long) sb.st_uid);
	printf("d. GID= %ld\n",(long)sb.st_gid);
	printf("e. File size: %lld bytes\n",(long long) sb.st_size);
	printf("f. block size:  %ld bytes\n",(long) sb.st_blksize);
  	printf("g. Number of blocks: %lld\n",(long long) sb.st_blocks);
  	printf("h. time of last access: %s", ctime(&sb.st_atime));
  	printf("i. time of last modification: %s", ctime(&sb.st_mtime));
	printf("j. time of last change %s", ctime(&sb.st_ctime));
  	exit(EXIT_SUCCESS);	
	
}

//OUTPUT
/*
File Type is q7ex2.txt
a. inode : 23478724
b. Number of hardlinks 1
c. UID= 1000 
d. GID= 1000
e. File size: 19 bytes
f. block size:  4096 bytes
g. Number of blocks: 8
h. time of last access: Thu Aug 22 14:23:55 2024
i. time of last modification: Thu Aug 22 14:22:11 2024
j. time of last change Thu Aug 22 14:22:11 2024

*/
