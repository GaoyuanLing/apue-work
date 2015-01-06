#include <fcntl.h>
#include "ourhdr.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <utime.h>

int main(int argc, char * argv[]){
    struct utimbuf timebuf;
    struct stat statbuf;
    int i;
    for(i = 1; i < argc; i++){
        if(stat(argv[i], &statbuf) < 0)
            err_sys("get stat error");

        if(open(argv[i], O_RDWR | O_TRUNC) < 0)
            err_sys("open error");

        timebuf.actime = statbuf.st_atime;
        timebuf.modtime = statbuf.st_mtime;
        if(utime(argv[i], &timebuf) < 0){
            err_sys("utime error");
        }
    }
    exit(0);
}

