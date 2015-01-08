#include <signal.h>

static void sig_int(int);

int main(void){
    sigset_t newmask, oldmask, waitmask;
    
    pr_mask("program start:");
   
    if(signal(SIGINT, sig_int) == SIG_ERR){
        err_sys("sigint error");
    }
   
    sigemptyset(&newmask);
    sigaddset(&newmask, SIGINT);
    sigemptyset(&waitmask);
    sigaddset(&waitmask, SIGUSR1);
    
    if(sigprocmask(SIG_BLOCK, &newmask, &oldmask) == -1){
        err_sys("sigprocmask error");
    }
   
    pr_mask("in critical region:");

    if(sigsuspend(&waitmask) != -1){
        err_sys("sigsuspend error");
    }
 
    pr_mask("after return from sigsuspend:");

    if(sigprocmask(SIG_SETMASK, &oldmask, 0) == -1){
        err_sys("sigprocmask setmask error");
    }

    pr_mask("program exit:");
    
    exit(0);
}

static void sig_int(int signo){
    pr_mask("sig inter:");    
}
