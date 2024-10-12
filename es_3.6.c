#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
//#include <asm-generic/signal.h>
#include <signal.h>


int main(){

    __pid_t procid, childPid;

    switch (procid = fork())
    {
    case -1:
        perror("fork failed");
        exit(EXIT_FAILURE);
    break;
    case 0:
        printf("figlio terminato\n");
        childPid = getpid();
        exit(0);
    break;
    default:
        printf("padre sleeping...\n");
        sleep(10);
        //wait(&childPid);
        kill(childPid, SIGKILL);
        printf("\tfiglio ucciso\n");
    break;
    }

    exit(0);

    return 0;
}