#include  <stdio.h>
#include  <sys/types.h>
#include  <string.h>
#include  <stdlib.h>
#include  <sys/wait.h>
#define   MAX_COUNT  200

void  ChildProcess(void);                /* child process prototype  */
void  ParentProcess(int);               /* parent process prototype */

void  main(void){
  int i = 0;
  pid_t  pid;
  int status;
  
  for (i = 0; i <= 2; i++){
    pid = fork();
    if (pid < 0){
    printf("Error: Fork Op\n");
  } else if (pid == 0){
    ChildProcess();
  }
  }
  for (int i = 0; i <= 2; i++){
    wait(&status);
    ParentProcess(status);
  }
}

void  ChildProcess(void)
{
  int i = 0;
  int num;
  srand(getpid());
  num = rand() % 30 + 1;

  for (i = 1; i <= num; i++)
    printf("Child with pid: %d is going to sleep for %d seconds!\n", getpid(), num);
    sleep(rand() % 10 + 1);
    printf("Child with pid: %dis awake! Where is my parent with pid: %d?\n", getpid(), getppid());
  printf("   *** Child process is done ***\n");
  exit(0);
}

void  ParentProcess(int stat)
{
  int   i;
  printf("Child Pid: %d has completed with exit status: %d!\n", getpid(), WEXITSTATUS(stat));
  printf("*** Parent is done ***\n");
}