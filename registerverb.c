#include "ourhdr.h"
#include <setjmp.h>

void f1(int, int, int);
void f2();

jmp_buf jumpbuffer;

int main(void){
    int count;
    register int val;
    volatile int sum;

    count = 2, val = 3, sum = 4;
    if(setjmp(jumpbuffer) != 0){
        printf("in f2();count = %d, val = %d, sum = %d\n", count, val, sum);
        exit(0);
    }
    count = 97, val = 98, sum = 99;
    f1(count, val, sum);
}

void f1(int count, int val, int sum){
    printf("in f1(), count = %d, val = %d, sum = %d\n", count , val ,sum);
    f2();
}

void f2(){
   longjmp(jumpbuffer, 1);
}
