#include "ourhdr.h"
#include <setjmp.h>

#define TOK_ADD 5

jmp_buf jumpbuffer;
void do_line(char *);
void cmd_add(void);
int get_token(void);

int main(void){
    char line[MAXLINE];
    
    if(setjmp(jumpbuffer) != 0)
         printf("error");

    while(fgets(line, MAXLINE, stdin) != NULL){
        do_line(line);
    }
  
    exit(0);
}

void do_line(char *ptr){
    int cmd;
    while((cmd = get_token()) > 0){
        switch(cmd){
             case TOK_ADD:
                 cmd_add();  
                 break;
        }
    }
}

void cmd_add(void){
    longjmp(jumpbuffer, 1);
}

int get_token(void){
    return 5;
}
