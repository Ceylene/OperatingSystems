//collaborated with Leandra McPhie and Summayyah Husain
/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>
 
bool alarm_trigger = false;
 
void handler(int signum){ //signal handler
 printf("Hello World!\n");
 alarm_trigger = true;
 // exit(1); //exit after printing
}
 
int main(int argc, char * argv[]){
 for(;;) {
   alarm_trigger = false;
   alarm(1); //Schedule a SIGALRM for 1 second
   signal(SIGALRM, handler); //register handler to handle SIGALRM
   while(alarm_trigger == false); //busy wait for signal to be delivered
     printf("Turing was right!\n");
 }
 return 0; //never reached
}
