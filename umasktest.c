#include "ourhdr.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void){
    umask(0);
    if(creat("foo", S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH) == -1)
        err_sys("create file error");

    umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    if(creat("test", S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH) == -1)
        err_sys("create file error");
    exit(0);
}
