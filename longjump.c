#include <setjmp.h>
#include "ourhrd.h"

#define TOK_ADD 5

jmp_buf jmpbuffer;

void do_line(char *);
void cmd_add(void);
void get_token(void);

int main(void){
    char line[MAXLINE];

    if(setjmp(jmpbuffer) != 0){
        printf("error");
    }

    while(fgets(line, MAXLINE, stdin) != NULL){
        do_line(line);
    }
    
    exit(0);    
}


void do_line(char *ptr){
    int cmd;
    tok_ptr = ptr;
    while((cmd = get_token()) > 0){
        switch(cmd){
            case TOK_ADD:
                cmd_add();
                break;
        }
    }
}

void cmd_add(void){
    int token;
    longjmp(jmpbuffer, 1);
}

void get_token(void){
    return 5;
}
