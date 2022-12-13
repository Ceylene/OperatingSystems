#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
 
int main(int argc, char **argv)
{
   int pipefd1[2];
   int pipefd2[2];
  
   int pid;
   int pid2;
 
   char *cat_arguments[] = {"cat", "scores", NULL};
   char *grep_arguments[] = {"grep", argv[1], NULL};
   char *sort_arguments[] = {"sort", NULL};
 
   if (pipe(pipefd1) == -1)
   {
       fprintf(stderr, "Pipe Failed");
       return 1;
   }
   if (pipe(pipefd2) == -1)
   {
       fprintf(stderr, "Pipe Failed");
       return 1;
   }
 
   pid = fork();
   if (pid < 0)
   {
       fprintf(stderr, "Fork Failed");
       return 1;
   }
 
   if (pid == 0)
   {
       pid2 = fork();
       if (pid2 < 0)
       {
           fprintf(stderr, "Fork Failed");
           return 1;
       }
 
       if (pid2 == 0)
       {
 
           dup2(pipefd1[1], 1);
           close(pipefd1[0]);
           close(pipefd2[1]);
           execvp("cat", cat_arguments);
       }
       else
       {
           dup2(pipefd1[0], 0);
           dup2(pipefd2[1], 1);
           close(pipefd1[1]);
           close(pipefd2[0]);
           execvp("grep", grep_arguments);
       }
   }
   else
   {
       dup2(pipefd2[0], 0);
       close(pipefd2[1]);
       close(pipefd1[1]);
       close(pipefd1[0]);
       execvp("sort", sort_arguments);
   }
   return 1;
}




