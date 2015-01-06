#include "ourhdr.h"

static void my_exit1(void);
static void my_exit2(void);
int main(void){
    if(atexit(my_exit1) != 0){
        err_sys("atexit error");
    } 
    if(atexit(my_exit2) != 0){
        err_sys("atexit error");
    } 
    if(atexit(my_exit2) != 0){
        err_sys("atexit error");
    } 
    exit(0);
}

static void my_exit1(void){
    printf("first exit\n");
}

static void my_exit2(void){
    printf("second exit\n");
}
