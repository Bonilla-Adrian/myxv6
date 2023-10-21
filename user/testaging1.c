#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(void) {
    int pid;
    int initial_priorities[] = {5, 10, 15, 20, 25};
    int num_processes = sizeof(initial_priorities) / sizeof(int);

    for (int i = 0; i < num_processes; i++) {
        pid = fork();
        if (pid == 0) {
            setpriority(getpid(), initial_priorities[i]);
            for (int j = 0; j < 100; j++) {
                printf("Process %d with initial priority %d now has priority %d\n",
                       getpid(), initial_priorities[i], getpriority(getpid()));
                sleep(10);  // Sleep for a while to allow other processes to run
            }
            exit(0);
        }
    }

    for (int i = 0; i < num_processes; i++) {
        wait(0);
    }

    exit(0);
}
