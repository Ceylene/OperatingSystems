/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>

bool trigger = false;

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  trigger = true;
  alarm(1);
  //exit(1); //exit after printing
}

int main(int argc, char * argv[])
{
  for (;;){
    trigger = false;
    alarm(1); //Schedule a SIGALRM for 1 second
    signal(SIGALRM, handler); //register handler to handle SIGALRM
    while(trigger == false){
      printf("Turing was right!\n");
      }
  }
  
  // do{
    
  //   sleep(1);
    
  // } while(1); //busy wait for signal to be delivered

  return 0; //never reached
}