#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
//#include <asm/signal.h>

int main(){

    __pid_t procPid;

    printf("NUM PROCESS:\t");
    scanf("%d", &procPid);

    if(kill(procPid, 0) == 0){
        printf("processo %d esiste\n", procPid);
    }else{
        if(errno == ESRCH){
            fprintf(stderr, "Errore: No such process (ESRCH)\n");
        }else if(errno == EPERM){
            fprintf(stderr, "Errore: Operation not permitted (EPERM)\n");        
        }else{
            fprintf(stderr, "Errore: %s\n", strerror(errno));
        }
    }
    return 0;
}

