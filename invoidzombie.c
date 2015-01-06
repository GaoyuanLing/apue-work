#include "ourhdr.h"

int main(void){
    pid_t pid;
  
    if((pid = fork()) < 0){
        err_sys("fork first child error");
    }
    else if(pid == 0){
        if((pid = fork()) < 0){
            err_sys("fork second child error");
        }
        else if(pid == 0){
            sleep(2);
            printf("pid = %d, parendid = %d\n", getpid(), getppid());
        }
        else if(pid > 0){
            exit(0);
        }
        exit(0);
    }
    if(waitpid(pid, NULL, 0) != pid){
        err_sys("waitpid error");
    }
    exit(0);
}
