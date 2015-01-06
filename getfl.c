#include <fcntl.h>
#include "apue.h"

int main(int argc, char *argv[]){
    int val;
    if(argc != 2)
        printf("error");
    if((val = fcntl(atoi(argv[1]),F_GETFL)) == -1){
        printf("error value");
    }
    if((val & O_ACCMODE) == O_RDONLY)
        printf("read only");
    if((val & O_ACCMODE) == O_WRONLY)
        printf("write only");
    if((val & O_ACCMODE) == O_RDWR)
        printf("both read write");

    if(val & O_APPEND)
        printf(",append");
    if(val & O_NONBLOCK)
        printf(",nonblock");
    if(val & O_SYNC)
        printf(",sync");
    if(val & O_ASYNC)
        printf(",async");
    printf("\n");
    exit(0);
}
