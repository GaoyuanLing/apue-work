#include "ourhdr.h"

int main(int argc, char* argv[]){
    if(argc != 3){
        err_quit("usage: a.out");
    }
 
    printf("%s, %s\n", argv[1][0] == ' ' ? NULL : argv[1], argv[2][0] == ' ' ? NULL : argv[2]);
    printf("%s\n", tempnam(argv[1][0] == ' ' ? NULL : argv[1], argv[2][0] == ' ' ? NULL : argv[2]));
    exit(0);
}
