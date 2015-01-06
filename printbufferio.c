#include "ourhdr.h"

void printio(const char* ,FILE *);

int main(void){
    FILE *fp;
    fputs("enter any character\n", stdout);
    if(getchar() == EOF){
        err_sys("get char error");
    }

    fputs("one line to stanard error\n", stderr);
    
    printio("stdin", stdin);
    printio("stdout", stdout);
    printio("stderr", stderr);
    
    if((fp = fopen("/home/lgy/deco.py", "r")) == NULL){
        err_sys("fopen error");
    }

    if(getc(fp) == EOF){
        err_sys("getc errr");
    }
    
    printio("/home/lgy/deco.py", fp);
    exit(0);
}

void printio(const char *string, FILE *fp){
    printf("stream = %s", string);
    if(fp -> _IO_file_flags & _IO_UNBUFFERED){
        printf(" unbuffered");
    }
    else if(fp -> _IO_file_flags & _IO_LINE_BUF){
        printf(" line buffer");
    }
    else
        printf(" full buffer");

    printf(",buffer size %ld\n", fp -> _IO_buf_end - fp -> _IO_buf_base);
}
