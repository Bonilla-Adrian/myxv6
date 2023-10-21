#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(void) {
    int pid = fork();

    if(pid == 0) {
        while(1) {
            printf("Child process %d with default priority\n", getpid());
            sleep(10);
        }
    } else {
        sleep(20);  // Let child run for a while
        setpriority(getpid(), 5);  // Increase priority of the current process
        while(1) {
            printf("Parent process %d with increased priority\n", getpid());
            sleep(10);
        }
    }

    exit(0);
}
