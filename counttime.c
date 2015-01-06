#include <sys/times.h>
#include "ourhdr.h"

void pr_time(clock_t, struct tms *, struct tms *);
void do_cmd(char *);

int main(int argc, char *argv[]){
    int i;
    for(i = 1; i < argc; i++){
        do_cmd(argv[i]);
    }
    exit(0);    
}

void do_cmd(char *cmdstring){
    struct tms tmsstart, tmsend;
    clock_t start, end;
    int status;
    printf("\ncommand: %s\n", cmdstring);
    
    if((start = times(&tmsstart)) == -1){
        err_sys("get start time error");
    }

    if((status = system(cmdstring)) < 0){
        err_sys("system() error");
    }

    if((end = times(&tmsstart)) == -1){
        err_sys("get end time error");
    }

    pr_time(end - start, &tmsstart, &tmsend);
}

void pr_time(clock_t interval, struct tms *start, struct tms *end){
    static long clktck = 0;
    if(clktck == 0)
        if((clktck = sysconf(_SC_CLK_TCK)) < 0)
            err_sys("sysconf error");

    printf("tck%7.2f\n", (double) clktck);
    printf("real %7.2f\n", interval / (double) clktck);
    printf("user: %7.2f\n", (end -> tms_utime - start -> tms_utime) / (double) clktck);
    printf("user: %ld\n", (end -> tms_utime - start -> tms_utime));
    printf("sys: %7.2f\n", (end -> tms_stime - start -> tms_stime) / (double) clktck);
    printf("sys: %ld\n", (end -> tms_stime - start -> tms_stime));
    printf("child-user: %7.2f\n", (end -> tms_cutime - start -> tms_cutime) / (double) clktck);
    printf("child-sys: %7.2f\n", (end -> tms_cstime - start -> tms_cstime) / (double) clktck);
}
