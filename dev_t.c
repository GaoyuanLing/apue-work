#include <sys/types.h>
#include <sys/stat.h>
#include "ourhdr.h"

int main(int argc, char *argv[]){
    int i;
    struct stat statbuf;
    for(i = 1; i < argc; i++){
        if(stat(argv[i], &statbuf) < 0){
            err_ret("stat error");
            continue;
        }

        printf("dev: %d / %d\n", major(statbuf.st_dev), minor(statbuf.st_dev));
        if(S_ISCHR(statbuf.st_mode) || S_ISBLK(statbuf.st_mode)){
            printf("%s: %d / %d\n", (S_ISCHR(statbuf.st_mode)? "character": "block"), major(statbuf.st_rdev), minor(statbuf.st_rdev));
        }
    }
    exit(0);
}
