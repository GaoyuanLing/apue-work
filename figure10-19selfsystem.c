#include <signal.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
#include "ourhdr.h"

static void sig_int(int signo){
    printf("caught signal SIGINT:\n");
}

static void sig_chld(int signo){
    printf("caught signal SIGCHLD\n");
}

int system(const char* cmdstr){
    pid_t pid;
    int status;
    struct sigaction ignore, saveintr, savequit;
    sigset_t chldmask, savemask;

    if(cmdstr == NULL){
        return(1);
    }

    ignore.sa_handler = SIG_IGN;
    sigemptyset(&ignore.sa_mask);
    ignore.sa_flags = 0;
    if(sigaction(SIGINT, &ignore, &saveintr) == -1){
        return(-1);
    }
    if(sigaction(SIGQUIT, &ignore, &savequit) == -1){
        return(-1);
    }
    sigemptyset(&chldmask);
    sigaddset(&chldmask, SIGCHLD);
    if(sigprocmask(SIG_BLOCK, &chldmask, &savemask) == -1){
        return(-1);
    }

    if((pid = fork()) < 0){
        status = -1;
    }else if(pid == 0){
        sigaction(SIGINT, &saveintr, NULL);
        sigaction(SIGQUIT, &savequit, NULL);
        sigprocmask(SIG_SETMASK, &savemask, NULL);
    
        execl("/bin/sh", "sh", "-c", cmdstr, (char*)0);
        _exit(127);
        
    }else{
        while(waitpid(pid, &status, 0) < 0){
            if(errno != EINTR){
                status = -1;
                break;
            }
        }
    }

    if(sigaction(SIGINT, &saveintr, NULL) == -1){
        return(-1);
    }
    if(sigaction(SIGQUIT, &savequit, NULL) == -1){
        return(-1);
    }
    if(sigprocmask(SIG_SETMASK, &savemask, NULL) < 0){
        return(-1);
    }
 
    return(status);
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
