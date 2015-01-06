#include "ourhdr.h"
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]){
    if(access(argv[1], R_OK) == -1){
        err_ret("access error for %s\n", argv[1]);
    }else{
        printf("reading ok\n");
    }

    if(access(argv[1], W_OK) == -1){
        err_ret("access error for %s\n", argv[1]);
    }else
        printf("writing ok\n");

    if(access(argv[1], X_OK) == -1){
        err_ret("access error for %s\n", argv[1]);
    }else
        printf("execute ok\n");
    if(open(argv[1], O_RDWR) == -1)
        err_ret("open error for %s\n", argv[1]);
    else
        printf("read and write");
       
    if(access(argv[1], F_OK) == -1){
        err_ret("access error for %s\n", argv[1]);
    }else
        printf("file does  exist\n");

    exit(0);
}
