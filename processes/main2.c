#include  <stdio.h>
#include  <sys/types.h>
#include  <string.h>
#include  <stdlib.h>
#include  <sys/wait.h>
#define   MAX_COUNT  200

void  ChildProcess(void);                /* child process prototype  */
void  ParentProcess(void);               /* parent process prototype */

void  main(void)
{
  pid_t  pid;
  int status;
  pid = fork();
  if (pid < 0){
    printf("Error: Fork Op\n");
  } else if (pid == 0){
    fork();
    ChildProcess();
  } else{
    wait(&status);
    ParentProcess(status);
  }
          
}

void  ChildProcess(void)
{
  int   i;
  int num = rand();
  sleep(num);
  for (i = 1; i <= MAX_COUNT; i++)
    num = rand() % 30 + 1;
    printf("Child with pid: %d is going to sleep for %d seconds!\n", getpid(), num);
    printf("   This line is from child, value = %d\n", i);
    sleep(num);
    printf("Child with pid: %dis awake! Where is my parent with pid: %d?\n", getpid(), getppid());
  printf("   *** Child process is done ***\n");
  exit(0);
}

void  ParentProcess(int stat)
{
  int   i;

  for (i = 1; i <= MAX_COUNT; i++)
    printf("This line is from parent, value = %d\n", i);
    printf("Child Pid: %d has completed with exit status: %d!\n", getpid(), stat);
  printf("*** Parent is done ***\n");
}