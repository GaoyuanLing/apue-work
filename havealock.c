#include <sys/types.h>
#include "ourhdr.h"

static void chartime(char *);
int main(void){
    pid_t pid;
    TELL_WAIT();
    if((pid = fork()) < 0){
        err_sys("fork error");
    }
    else if(pid == 0){
         WAIT_PARENT();
         chartime("out put from child\n");
    }else{
         chartime("out put from parent\n");
         TELL_CHILD(pid);
    }
    exit(0);
}

static void chartime(char *str){
    char *s;
    int c;
    setbuf(stdout, NULL);
    for(s = str; c = *s; s++){
        putc(c, stdout);
    }
}

