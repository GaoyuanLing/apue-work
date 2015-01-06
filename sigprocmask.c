#include "ourhdr.h"
#include <signal.h>

static void sig_quit(int);
int main(void){
    sigset_t newmask, oldmask, pendmask;
    
    if(signal(SIGQUIT, sig_quit) == SIG_ERR){
        err_sys("cannot catch quit");
    }

    sigemptyset(&newmask);
    sigaddset(&newmask, SIGQUIT);
    if(sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0){
        err_sys("sigprocmask error");
    }
    sleep(5);
    
    if(sigpending(&pendmask) < 0){
        err_sys("sigpending error");
    }
    
    if(sigismember(&pendmask, SIGQUIT))
        printf("sigquit is member\n");

    if(sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0){
        err_sys("sigpromask error");
    }
    printf("sigquit unblock\n");
    
    sleep(5);

    exit(0);

}

static void sig_quit(int signo){
    printf("caught sigquit signal\n");
    
    if(signal(SIGQUIT, SIG_DFL) == SIG_ERR){
        err_sys("reset siqquit error");
    }
    return;
}
