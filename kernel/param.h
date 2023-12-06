#define NPROC        64  // maximum number of processes
#define NCPU          8  // maximum number of CPUs
#define NOFILE       16  // open files per process
#define NFILE       100  // open files per system
#define NINODE       50  // maximum number of active i-nodes
#define NDEV         10  // maximum major device number
#define ROOTDEV       1  // device number of file system root disk
#define MAXARG       32  // max exec arguments
#define MAXOPBLOCKS  10  // max # of blocks any FS op writes
#define LOGSIZE      (MAXOPBLOCKS*3)  // max data blocks in on-disk log
#define NBUF         (MAXOPBLOCKS*3)  // size of disk block cache
#define FSSIZE       1000  // size of file system in blocks
#define MAXPATH      128   // maximum file path name
#define SCHED_DEFAULT  0   // Default round-robin scheduling policy
#define SCHED_PRIORITY 1   // Priority-based scheduling policy
#define SCHED_TYPE SCHED_PRIORITY  // Setting for which Scheduler to use (round-robin or priority)
#define AGING_THRESHOLD 30  // Number of ticks after which aging is applied
#define AGING_AMOUNT 1      // Amount by which priority is increased during aging
#define MAX_PRIORITY 99  // Maximum priority value a process can have
#define MAX_MMR	10   // maximum number of memory-mapped regions per process


enum procstate { UNUSED, USED, SLEEPING, RUNNABLE, RUNNING, ZOMBIE };
