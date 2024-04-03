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

  printf("NAME    PID     STATUS          COLOR           TICKETS\n");
  
  for(int i = 0; i < NPROC; i++)
  {
    // don't print pids we haven't used
    if(structure.pid[i] == 0)
    {
      break;
    }

    printf("%s\t", structure.name[i]);
    printf("%d\t", structure.pid[i]);

    switch(structure.state[i])
    {
      case 0:
        printf("UNUSED\t\t");
        break;
      case 1:
        printf("USED\t\t");
        break;
      case 2:
        printf("SLEEPING\t");
        break;
      case 3:
        printf("RUNNABLE\t\t");
        break;
      case 4:
        printf("RUNNING\t\t");
        break;
      case 5:
        printf("ZOMBIE\t\t");
        break;
      default:
        printf("FAILURE\t\t");
    }

    switch(structure.color[i])
    {
      case 0:
        printf("RED\t\t");
        break;
      case 1:
        printf("ORANGE\t\t");
        break;
      case 2:
        printf("YELLOW\t\t");
        break;
      case 3:
        printf("GREEN\t\t");
        break;
      case 4:
        printf("BLUE\t\t");
        break;
      case 5:
        printf("INDIGO\t\t");
        break;
      default:
        printf("VIOLET\t\t");
    }

    printf("%d", structure.tickets[i]);

    printf("\n");
  }
  
  exit(0);
}
