#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
    int pid;

    // Fork a child process
    pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        exit(1);
    }

    if (pid == 0) { // Child process
        printf("Child process\n");
        exit(0);
    } else { // Parent process
        printf("Parent process\n");

        // Display process info using the modified ps command
        if (fork() == 0) {
            char *args[] = {"ps", 0};
            exec("ps", args);
            exit(0); // exit if exec fails
        }
        wait(0); // wait for the child process to finish
    }

    exit(0);
}

