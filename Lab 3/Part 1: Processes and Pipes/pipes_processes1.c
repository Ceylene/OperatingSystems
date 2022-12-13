// C program to demonstrate use of fork() and pipe()
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>
 int main() {
  // We use two pipes
  // First pipe to send input string from parent
  // Second pipe to send concatenated string from child
  int fd1[2];  // Used to store two ends of first pipe
  int fd2[2];  // Used to store two ends of second pipe
  // char fixed_str[] = "howard.edu";
  char input_str[100];
  char input_str2[100];
  pid_t p;
  if (pipe(fd1) == -1) {
    fprintf(stderr, "Pipe Failed" );
    return 1;
  }
  if (pipe(fd2) == -1) {
    fprintf(stderr, "Pipe Failed" );
    return 1;
  }
  printf("Enter a string to concatenate: ");
  scanf("%s", input_str);
  p = fork();
  
  if (p < 0) {
    fprintf(stderr, "fork Failed" );
    return 1;
  }
  // Parent process
  else if (p > 0) {
    close(fd1[0]);  // Close reading end of pipes
    close(fd2[1]);  // Close the writing end of pipe - recieves the message
    
    // Write input string and close writing end of first
    // pipe.
    write(fd1[1], input_str, strlen(input_str)+1);
    
    read(fd2[0], input_str, 100);
    
    // Wait for child to send a string
    wait(NULL);
    printf("Enter a string to concatenate: ");
    scanf("%s", input_str2);
    
    strcat(input_str, input_str2);
    printf("Parent string: %s\n", input_str);
    
    //close(fd2[0]); // Close writing end of pipes
    //close(fd1[1]);
  }
  
  // child process
  else {
    close(fd1[1]);  // Close writing end of first pipes
    close(fd2[0]);  // Close the reading end of the pipe
    
    char concat_str[100];
    read(fd1[0], concat_str, 100);
    
    strcat(concat_str, "howard.edu");
    write(fd2[1], concat_str, strlen(concat_str)+1);
    
    printf("Child string: %s\n", concat_str);
    // Close both reading ends
    exit(0);
  } 
}