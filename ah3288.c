#include <stdlib.h>
#include <stdio.h>

#include<sys/types.h>


  void main () {
    while(1){
        printf(“lab1> “);
        char* usin;
        scanf("%s", usin);
        printf(“Parent Process %d\n”, getpid());

        // Built in commands
        char[] prid = "printid";
        char[] ex= "exit";
        char[] gr = "greet";

        if (strcmp(usin,prid)== 0) {
            printf("The ID of the current process is %d", getpid());
        }
        else if (strcmp(usin, ex)==0) {
            exit(0);
        }
        else if (strcm(usin, gr)==0) {
            printf("Hello\\n");
        }

         else {
             int pid;
             pid = fork();
             if( pid == 0 ) {
             printf(“Child process %d will execute the command %s\n”,getpid(), usin);

             char* str = "/bin/";

             char* istr = strcat(str, usin);

             char* argv [] = {usin , NULL};

             execve(istr , argv, NULL);

             printf("Command not found!\n");
          }

        wait(NULL);
    }
  }