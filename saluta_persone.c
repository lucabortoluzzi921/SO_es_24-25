#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int main(int argc, char *argv[]){

    for(size_t i = 1; i <= argc; i++){
        printf("%s\n", argv[i]);
    }

    return 0;
}