//collaborated with Leandra McPhie and Summayyah Husain

/* timer.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>
 
bool alarm_trigger = false;
int start_time;
int end_time;
int alarm_count = 0;
 
void time_handler(int sigint){
 int total_time;
 end_time = time(NULL);
 total_time = end_time - start_time;
 printf("\nTotal number of seconds = %d\nAlarm count = %d\n", total_time, alarm_count);
 exit(0);
}
 
void handler(int signum)
{ //signal handler
 printf("Hello World!\n");
 alarm_trigger = true;
 alarm_count++;
 // exit(1); //exit after printing
}
 
int main(int argc, char * argv[])
{
 start_time = time(NULL);
 signal(SIGINT, time_handler);
 signal(SIGALRM, handler); //register handler to handle SIGALRM
 for(;;) {
   alarm_trigger = false;
   alarm(3); //Schedule a SIGALRM for 1 second
   while(alarm_trigger == false); //busy wait for signal to be delivered
     printf("Turing was right!\n");
 }
 return 0; //never reached
}