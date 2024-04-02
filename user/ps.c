// Will Maberry

#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

enum procstate { UNUSED, USED, SLEEPING, RUNNABLE, RUNNING, ZOMBIE };
enum COLOR { RED, ORANGE, YELLOW, GREEN, BLUE, INDIGO, VIOLET };

#include "kernel/pstat.h"

int main(void)
{
  struct pstat structure;
  getpinfo(&structure);
  printf("NAME     PID     STATUS     COLOR     TICKETS\n");
  printf("\n");
  for(int i=0; i<NPROC; i++)
  {

  }
  exit(0);
}
