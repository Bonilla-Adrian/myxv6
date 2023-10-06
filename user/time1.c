#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

char *argv1[1000];

int main(int argc, char **argv)
{
	//Make a copy of the args
	for(int i = 1; i < argc; i++)
	{
		argv1[i-1] = argv[i];
	}

	argv1[argc-1] = 0; //Last element is made Null for Exec

	int startTime = uptime();
	int endTime = 0;
	int c_pid = fork();

	//Check if the fork process failed
	if(c_pid < 0)
	{
		printf("Fork process failed...\n");
		exit(1);
	}

	else if(c_pid == 0)//If currently in the child process
	{
		//Execute the child process
		exec(argv1[0], argv1);

		//Exit in case exec fails
		exit(1);
	}
	else //If in the parent process
	{
		int c_wait = wait((int*) 0);
		if(c_wait == c_pid)
		{
			endTime = uptime();//Record the uptime after child process finishes
			printf("Elapsed time: %d\n", endTime-startTime);
			exit(0);
		}
		else if(c_wait < 0)
		{
			printf("An error occured when returning to parent\n");
			exit(1);
		}
		else
		{
			exit(1);
		}
	}
}
