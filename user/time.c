#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/param.h"
#include "kernel/pstat.h"

char *argv1[1000];
struct rusage argv_sec2;

int main(int argc, char **argv)
{
printf("henlo");
for(int i = 1; i < sizeof(argv); i++)
{
  argv1[i-1] = argv[i];
}

  int startTime = uptime();
  int endTime = 0;
  int c_pid = fork();
  if(c_pid<0)
  {
    printf("Fork has failed, and no child has been made\n");
    exit(1);
  }
  else if(c_pid == 0)
  {
    printf("Howdy I'm child (pid:%d)\n", (int) getpid());
    exec(argv1[0], argv1);
    // this shouldn't work at all
    printf("looks like execv failed \n");
    exit(1);
  }
  else
  {
    int c_wait = wait2( 0, &argv_sec2);
    if(c_wait < 0)
    {
      printf("back to parent process\n");
      endTime = uptime();
      printf("total running time: %d\n", endTime-startTime);
      exit(0);
    }
    // stop measuring CPU time
    int end_ticks = uptime();
    
    int elapsed_time = end_ticks - startTime;
    int cpu_time = argv_sec2.cputime;
    int cpu_percentage = (cpu_time *100) / elapsed_time;
    printf("elapsed time: %d ticks, CPU time: %d ticks, %d CPU\n", elapsed_time, cpu_time, cpu_percentage);
    exit(0);
  }
}
