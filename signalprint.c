#include "apue.h"
#include <sys/wait.h>

static void sig_int(int);

int main(void){
    char buf[MAXLINE]; //MAXLINE defined in apue
    pid_t pid;
    int status;

    if(signal(SIGINT, sig_int) == SIG_ERR)
        printf("signal error");

    printf("@@@@@@\n");
    while(fgets(buf, MAXLINE, stdin) != NULL){
        if(buf[strlen(buf) - 1] == '\n')       
            buf[strlen(buf) - 1] = 0;
        if((pid = fork()) < 0){
            printf("error pid");
        }else if(pid == 0){
            execlp(buf, buf, (char*)0);
            printf("couldnot execute %s", buf);
            exit(127);
        }

        if ((pid  = waitpid(pid, &status, 0)) < 0)
            printf("wait_pid error");
    
        printf("@@@@@@\n");
    }
    exit(0);
}

void sig_int(int signo){
    printf("interupt\n ============");
}
