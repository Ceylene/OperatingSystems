/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>


int num_alarms = 0;
time_t start_time;
time_t end_time; 
time_t total_secs;
bool trigger = false;

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  trigger = true;
  num_alarms++;
  //exit(1); //exit after printing
}

void handler_sigint(int sec){
  end_time = time(NULL);
  total_secs = end_time - start_time;
  printf("\nNumber of alarms: %d \n", num_alarms);
  printf("The program was executing for; %ld seconds \n", total_secs);
  exit(0);
}

int main(int argc, char * argv[])
{
  start_time = time(NULL);
  signal(SIGINT, handler_sigint);
  signal(SIGINT, handler);
  for(;;){
    trigger = false;
    signal(SIGALRM,handler); //register handler to handle SIGALRM
    alarm(1); //Schedule a SIGALRM for 1 second
    // num_alarms += 1;
    // sleep(1);
    while(trigger == false){
      printf("Turing was right!\n");
    }    
  }

  return 0; //never reached
}