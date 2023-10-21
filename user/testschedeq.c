#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(void) {
    int pid;

    for(int i = 0; i < 3; i++) {
        pid = fork();
        if(pid == 0) {
            while(1) {
                printf("Process %d with equal priority\n", getpid());
                sleep(10); // Sleep to allow other processes to get scheduled
            }
        }
    }

    // Parent waits for all children to finish
    while(wait(0) != -1);

    exit(0);
}
