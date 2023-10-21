#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/pstat.h"
#include "user/user.h"

int
main(int argc, char **argv)
{
  struct pstat uproc[NPROC];
  int nprocs;
  int i;
  char *state;
  static char *states[] = {
    [SLEEPING]  "sleeping",
    [RUNNABLE]  "runnable",
    [RUNNING]   "running ",
    [ZOMBIE]    "zombie  "
  };

  nprocs = getprocs(uproc);
  if (nprocs < 0)
    exit(-1);

  // Updated to include the priority and age columns
  printf("pid\tstate\t\tsize\tppid\tname\tpriority\tage\n");
  for (i=0; i<nprocs; i++) {
    state = states[uproc[i].state];
    int current_ticks = uptime();
    // Updated to print the priority of each process and its age if it's RUNNABLE
    if (uproc[i].state == RUNNABLE) {
      printf("%d\t%s\t%l\t%d\t%s\t%d\t%d\n", uproc[i].pid, state,
                   uproc[i].size, uproc[i].ppid, uproc[i].name, uproc[i].priority, current_ticks - uproc[i].readytime);
    } else {
      printf("%d\t%s\t%l\t%d\t%s\t%d\t-\n", uproc[i].pid, state,
                   uproc[i].size, uproc[i].ppid, uproc[i].name, uproc[i].priority);
    }
  }

  exit(0);
}


