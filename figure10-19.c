#include "ourhdr.h"
#include <signal.h>

static void sig_int(int signo){
    printf("caught signal SIGINT:\n");
}

static void sig_chld(int signo){
    printf("caught signal SIGCHLD\n");
}

int main(void){
    if(signal(SIGINT, sig_int) == SIG_ERR){
        err_sys("signal INT error");
    }
    if(signal(SIGCHLD, sig_chld) == SIG_ERR){
        err_sys("signal CHLD error");
    }

    if(system("/bin/ed") < 0){
        err_sys("system error");
    }
    exit(0);
}
