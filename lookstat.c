#include "ourhdr.h"
#include <sys/types.h>
#include <sys/stat.h>
#define S_IStestDIR(mode) ((mode & S_IFMT) == S_IFDIR)

int main(int argc, char *argv[]){
    char *ptr;
    struct stat buf;
    int i;
    printf("%d\n", argc);
    for(i = 1; i< argc; i++){
        printf("%s:", argv[i]);
        if(lstat(argv[i], &buf) == -1)
        {
            err_ret("argc error");
            continue;
        }
   
        if(S_ISREG(buf.st_mode)) ptr = "regular file";    
        else if(S_IStestDIR(buf.st_mode)) ptr = "dir file";    
        else if(S_ISCHR(buf.st_mode)) ptr = "char file";    
        else if(S_ISBLK(buf.st_mode)) ptr = "block file";    
        else if(S_ISFIFO(buf.st_mode)) ptr = "fifo file";
#ifdef S_ISLNK
        else if(S_ISLNK(buf.st_mode)) ptr = "link file";
#endif
        
#ifdef S_ISSOCK
        else if(S_ISSOCK(buf.st_mode)) ptr = "sock file";
#endif
        else ptr = "unknown mode";
        printf("%s\n", ptr);
      
        printf("\n");
    } 
    exit(0);
}
