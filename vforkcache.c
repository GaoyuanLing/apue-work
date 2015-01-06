#include <sys/types.h>
#include "ourhdr.h"

int glob = 6;

int main(void){
    int var;
    pid_t pid;
   
    var = 8;
    printf("before vfork\n");

    if((pid = vfork()) == -1){
        err_sys("fork error");
    }else if(pid == 0){
        glob ++;
        var ++;
        exit(0);
    }else{
        sleep(2);
    }
    printf("pid = %d, glob = %d, var = %d\n", getpid(), glob, var);
    exit(0);
}
