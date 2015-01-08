#include "ourhdr.h"
#include <signal.h>

volatile int quitflag = 1;

static void sig_int(int signo){
    if(signo == SIGINT){
        printf("int\n");
    }else if(signo == SIGQUIT){
        quitflag = 0;
    }
}

int main(void){
    sigset_t newmask, oldmask, zeromask;
    
    if(signal(SIGINT, sig_int) == SIG_ERR){
        err_sys("sigint error");
    }

    if(signal(SIGQUIT, sig_int) == SIG_ERR){
        err_sys("sigguit error");
    }

    sigemptyset(&zeromask);
    sigemptyset(&newmask);
    sigaddset(&newmask, SIGQUIT);
    if(sigprocmask(SIG_BLOCK, &newmask, &oldmask) == -1){
        err_sys("SIG_BLOCK error");
    }
 
    while(quitflag == 1){
        printf("test\n");
        sigsuspend(&zeromask);
    }

    if(sigprocmask(SIG_SETMASK, &oldmask, 0) == -1){
        err_sys("sigprocmask sig_setmask error");
    }
    exit(0);
}
