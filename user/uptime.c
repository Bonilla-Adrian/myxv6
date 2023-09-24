#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char **argv)
{
	int ticks = uptime(); //Call uptime syscall to retrieve number of ticks
	if(ticks < 0){
		fprintf(2, "uptime: error in obtaining ticks\n");
		exit(1);
	}
	printf("%d\n", ticks); //Print the number of ticks in the console
	exit(0); //Exit normally
}
