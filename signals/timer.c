/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


int num_alarms = 0;
time_t start_time;
time_t end_time; 
time_t total_secs;
void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  //exit(1); //exit after printing
}

void handler_sigint(int sec){
  end_time = time(NULL);
  total_secs = end_time - start_time;
  printf("\nNumber of alarms: %d \n", num_alarms);
  printf("The program was executing for; %ld seconds \n", total_secs);
  exit(1);
}

int main(int argc, char * argv[])
{
  start_time = time(NULL);
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  signal(SIGINT, handler_sigint);
  do{
    alarm(1); //Schedule a SIGALRM for 1 second
    num_alarms += 1;
    sleep(1);
    printf("Turing was right!\n");
  } while(1); //busy wait for signal to be delivered

  return 0; //never reached
}