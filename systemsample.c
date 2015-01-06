#include "ourhdr.h"
#include <sys/types.h>
#include <sys/wait.h>

int main(void){
    printf("real uid = %d, and euid = %d\n", getuid(), geteuid());
    exit(0);
}

