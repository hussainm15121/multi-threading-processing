/***************************************
* PURPOSE: IMPLEMENT SYSTEM CALLS	 *
* AUTHOR: HUSSAIN MEHDI		 *
****************************************/
#define _GNU_SOURCE		
#include <sched.h>		//Included preprocessor directives
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#define FIBER_STACK 8192

int execFirst(void *arg)	
{
	char* data = arg;
	int pid;
	
    int fd = open("test.txt", O_RDONLY);		//Using open system call to open test.txt, with read only function
    if(fd<0)						//Error checking if file not found
    {
    	perror("ERROR READING FILE");
    }
    else
    {
    int n = read(fd, data, 20);			//Reading the file using read system call
    }
}

int main(void)
{
	int status;
    FILE* fp;
    char* str;
    str = (char*)malloc(sizeof(char)*20);

	void * stack;
      	stack = malloc(FIBER_STACK);

	pid_t cpid;		//clone process id

	cpid= clone(execFirst, (char *)stack + FIBER_STACK, CLONE_VM|CLONE_VFORK, str);    //using clone() to create process

	if(cpid == -1)			//catch errors during clone
	{
		perror("clone");
	}

    waitpid(-1,&status, 0);	//processes exit
    printf("%s", str);					//Printing the contents of file to the screen
    free(str);						//Freeing malloced data type
    free(stack);			//Freeing stack used during cloning
}
