#include "apue.h"

#define BUFFERSIZE 4096

int main(void){
    int n;
    char buf[BUFFERSIZE];
    
    while((n = read(STDIN_FILENO, buf, BUFFERSIZE)) > 0){
        if(write(STDOUT_FILENO, buf, n) != n)
            //err_sys("write error");
            printf("write error");
    }

    if(n < 0)
        //err_sys("read error");
        printf("read error");
    exit(0);
}
