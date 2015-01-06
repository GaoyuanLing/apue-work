#include "apue.h"

int main(void){
    char buf1[] = "ABCDEFGH";
    char buf2[] = "abcdefgh";
    int fd;
  
    if((fd = creat("file.hole", FILE_MODE)) == -1)
        printf("create file error");
    if(write(fd, buf1, sizeof(buf1)) == -1)
        printf("write error");
    if(lseek(fd, 100000, SEEK_CUR) == -1)
        printf("seek error");
    if(write(fd, buf2, sizeof(buf2)) == -1)
        printf("write error");
    exit(0);
    
}
