#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

void cpu_bound_task(int duration) {
    int start_ticks = uptime();
    while ((uptime() - start_ticks) < duration) {
        // Busy loop to keep the CPU occupied
    }
}

int main(void) {
    int pid;
    int start_ticks, end_ticks;

    // Create a child process
    pid = fork();

    if (pid == 0) {
        // Child process with lower initial priority
        setpriority(pid, 1); // Set low priority
        printf("Child process with low priority started\n");
        start_ticks = uptime();
        cpu_bound_task(500); // Run a CPU-bound task for 500 ticks
        end_ticks = uptime();
        printf("Low priority process turnaround time: %d ticks\n", end_ticks - start_ticks);
        exit(0);
    } else {
        // Parent process with higher initial priority
        setpriority(pid, 10); // Set high priority
        printf("Parent process with high priority started\n");
        start_ticks = uptime();
        cpu_bound_task(500); // Run a CPU-bound task for 500 ticks
        end_ticks = uptime();
        printf("High priority process turnaround time: %d ticks\n", end_ticks - start_ticks);
        wait(0); // Wait for child to finish
    }

    exit(0);
}

