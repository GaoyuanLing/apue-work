#include "ourhdr.h"
#include <signal.h>

static void sig_func(int);

int main(void){
    if(signal(SIGUSR1, sig_func) == SIG_ERR){
        err_sys("signal 1 catch error");
    }else if(signal(SIGUSR2, sig_func)){
        err_sys("signal 2 catch error");
    }
    for( ; ; ){
        pause();
    }

}

static void sig_func(int signo){
    if(signo == SIGUSR1){
        printf("catch signal user1");
    }else if(signo = SIGUSR2){
        printf("catch signal user2");
    }else{
        err_dump("receive signal %d\n", signo);
    }
}
