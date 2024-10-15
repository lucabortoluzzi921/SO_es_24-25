#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define ARR_LEN 5

int main(int argc, char *argv[]){
    /*if (argc < 2) {
        printf("Usage: %s <program_to_execute> [names...]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    __pid_t procid;

    switch (procid = fork())
    {
    case -1:
        perror("fork failed");
        exit(EXIT_FAILURE);
    case 0:
        // Child process: execute the program with the provided arguments
        execlp(argv[1], argv[1], argv[2], argv[3], argv[4], argv[5], NULL);
        perror("execlp failed");
        exit(EXIT_FAILURE);
    default:
        // Parent process: wait for the child to finish
        wait(NULL);
    }*/

    return 0;
}