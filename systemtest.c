#include "ourhdr.h"

int system1(char *cmdstring){
    pid_t pid;
    int status;

    if (cmdstring == NULL){
        return(1);
    }
    if((pid = fork()) < 0){
        status = -1;
    }else if(pid == 0){
        execl("/bin/sh", "sh", "-c", cmdstring, (char *) 0);
        _exit(127);
    }else{
         while(waitpid(pid, &status, NULL) < 0){
             if(errno != EINTR){
                 status = -1;
                 break;
             }
         }
    }
    return(status);
}

int main(int argc, char* argv[]){
    if(system1(argv[1]) < 0){
        err_sys("system error");
    }
    exit(0);
}
