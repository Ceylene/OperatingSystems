#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>
 
#define MAX_COMMAND_LINE_LEN 1024
#define MAX_COMMAND_LINE_ARGS 128
 
char prompt[256] = "> ";
char delimiters[] = " \t\r\n";
extern char **environ;
int child_pid;
 
void sigint_handler(int sigint){
 kill(child_pid, SIGKILL);
}
 
void sigalarm_handler(int sigalarm){
 exit(0);
}
 
int main() {
   // Stores the string typed into the command line.
   char command_line[MAX_COMMAND_LINE_LEN];
   char cmd_bak[MAX_COMMAND_LINE_LEN];
    // Stores the tokenized command line input.
   char *arguments[MAX_COMMAND_LINE_ARGS];
   int i = 0;
   pid_t  pid;
   int timer;
   int status; //for wait
   int status_code; //for execvp
   char *env_name;
   char *env_value;
   bool background_child;
 
   while (true) {
       background_child = false;
       signal(SIGINT, sigint_handler);
       do{
           // Print the shell prompt.
           // 0. Modify the prompt to print the current working directory
           if (getcwd(prompt, sizeof(prompt)) == NULL) {
               perror("getcwd() error :(");
               exit(1);
           }
           else {
               printf("%s>", prompt);
               fflush(stdout);
           }
           // Read input from stdin and store it in command_line. If there's an
           // error, exit immediately. (If you want to learn more about this line,
           // you can Google "man fgets")
      
           if ((fgets(command_line, MAX_COMMAND_LINE_LEN, stdin) == NULL) && ferror(stdin)) {
               fprintf(stderr, "fgets error");
               exit(0);
           }
       }while(command_line[0] == 0x0A);  // while just ENTER pressed
 
    
       // If the user input was EOF (ctrl+d), exit the shell.
       if (feof(stdin)) {
           printf("\n");
           fflush(stdout);
           fflush(stderr);
           return 0;
       }
 
       // TODO:
      
       // 1. Tokenize the command line input (split it on whitespace)
       arguments[0] = strtok(command_line, delimiters);
      
       int i = 0;
       while (arguments[i] != NULL) {
           // printf("%s\n", arguments[i]);
           i++;
           arguments[i] = strtok(NULL, delimiters);
       }
    
       if (strcmp(arguments[i-1], "&") == 0) {
         background_child = true;
         arguments[i - 1] = '\0';
       }
 
       // 2. Implement Built-In Commands
       if (strcmp(arguments[0], "cd") == 0){
           chdir(arguments[1]);
       }
       else if (strcmp(arguments[0], "pwd") == 0) {
           printf("%s\n", prompt);
       }
       else if (strcmp(arguments[0], "echo") == 0) {
           int i = 1;
           while (arguments[i] != NULL) {
             // loop through arg to print multiple echos
               if (*arguments[i] == '$') {
                   printf("%s", getenv((arguments[i] + 1)));
               }
               else {
                   printf("%s", arguments[i]);
               }
               i++;
           }
           printf("\n");
       }
       else if (strcmp(arguments[0], "exit") == 0) {
           exit(0);
       }
       else if (strcmp(arguments[0], "env") == 0) {
           printf("%s\n", getenv(arguments[1]));
       }
       else if (strcmp(arguments[0], "setenv") == 0) {
           if (arguments[1] == NULL) {
             printf("usage setenv <environment name>=<value>\n");
           }
           else{
             env_name = strtok(arguments[1], "=");
             env_value = strtok(NULL, "=");
             setenv(env_name, env_value, 1);
           }
          
       }
  
       // 3. Create a child process which will execute the command line input
       else {
           child_pid = fork();
           if (child_pid == 0) {
             alarm(10);
             status_code = execvp(arguments[0], arguments);
 
             if (status_code == -1) {
                 printf("execvp() failed: No such file or directory\nAn error occurred.\n");
                 exit(1);
             }
           }
           else if (child_pid < 0) {
             perror("pid error\n");
             exit(1);
           }
           else {
             // 4. The parent process should wait for the child to complete unless its a background process
             if (background_child == false){
               wait(&status);
             }
           }
       }
 
       // Hints (put these into Google):
       // man fork
       // man execvp
       // man wait
       // man strtok
       // man environ
       // man signals
      
       // Extra Credit
       // man dup2
       // man open
       // man pipes
   }
   // This should never be reached.
   return -1;
}
