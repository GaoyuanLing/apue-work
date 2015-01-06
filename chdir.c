#include "ourhdr.h"

int main(void){
    if(chdir("/home/lgy/nodejsstart") < 0)
        err_sys("change dir error");
    printf("change dir to nodejsstart\n");
    exit(0);
}
