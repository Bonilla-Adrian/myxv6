#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(void) {
    int pid;

    for(int i = 0; i < 3; i++) {
        pid = fork();
        if(pid == 0) {
            setpriority(getpid(), 3 - i);  // Set descending priorities for the current process
            while(1) {
                printf("Process %d with priority %d\n", getpid(), 3 - i);
                sleep(10);
            }
        }
    }

    // Parent waits for all children to finish
    while(wait(0) != -1);

    exit(0);
}

