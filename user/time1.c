#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: time1 command [args...]\n");
        exit(1);
    }

    int start_time = uptime();

    int pid = fork();
    if (pid == 0) {
        // In child
        exec(argv[1], &argv[1]);
        printf("time1: command not found\n");
        exit(1);
    } else {
        // In parent
        wait(0);
        int end_time = uptime();
        printf("elapsed time: %d ticks\n", end_time - start_time);
    }

    exit(0);
}
