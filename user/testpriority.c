#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(void)
{
    int pid = fork();
    if(pid == 0) { // Child process
        printf("Child process (PID: %d) default priority:\n", getpid());
        system("ps"); // Display process info using the modified ps command

        setpriority(getpid(), 10);
        printf("\nChild process (PID: %d) priority after setting to 10:\n", getpid());
        system("ps"); // Display process info again

        exit(0);
    } else { // Parent process
        wait(0);
    }
    exit(0);
}
