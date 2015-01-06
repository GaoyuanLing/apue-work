#include "ourhdr.h"

int main(void){
    char buf[MAXLINE];
    while(fgets(buf, MAXLINE, stdin) != NULL){
        if(fputs(buf, stdout) == EOF){
            err_sys("stdout error");
        }
    }

    if(feof(stdin) != 0){
        err_sys("file end");
    }

    if(ferror(stdout) != 0)
        err_sys("stdout error");
    
    exit(0);
}
