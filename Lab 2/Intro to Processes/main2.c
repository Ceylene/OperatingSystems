#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
 

// collaborated with Leandra McPhie and Sumayyah Husain

void  ChildProcess(void);                /* child process prototype  */
void  ParentProcess(int);               /* parent process prototype */
 
void  main(void)
{
   pid_t  pid;
   int status;
   int i;
   for (i = 1; i <= 2; i++) {
     pid = fork();
     if (pid < 0)
       printf("Error: Fork Op\n");
     else if (pid == 0) {
         ChildProcess();
     }
   }
   for (i = 1; i <= 2; i++) {
     wait(&status);
     ParentProcess(status);
   }
}
 
void  ChildProcess(void)
{
   int   i;
   int num;
   srand(getpid());
   num = rand() % 30 + 1;
   for (i = 1; i <= num; i++) {
       printf("   Child Pid: %d is going to sleep for %d seconds!\n", getpid(), num);
       sleep(rand() % 10 + 1);
       printf("   Child Pid: is awake! Where is my Parent: %d?\n", getppid());
   }
   printf("   *** Child process is done ***\n");
   exit(0);
}
 
void  ParentProcess(int stat)
{
   int   i;
   printf("Child Pid: %d has completed with exit status: %d\n", getpid(), WEXITSTATUS(stat));
   printf("*** Parent is done ***\n");
}


