#include "ourhdr.h"
#include <sys/types.h>
#include <sys/stat.h>

int main(void){
    struct stat statbuf;
    if(stat("foo", &statbuf)  == -1){
        err_sys("get stat error");
    }
   
    if(chmod("foo", (statbuf.st_mode & ~S_IRWXG) | S_ISGID) == -1){
        err_sys("chmod error");
    }

    if(chmod("test", S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP) == -1){
        err_sys("chmod error");
    }
    exit(0);
}
