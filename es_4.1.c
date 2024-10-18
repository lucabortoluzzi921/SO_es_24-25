#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int main(){
    
    __pid_t procPid, procPchild;

    switch(procPid = fork()){
        case -1:
            perror("Fork fallita");
            exit(EXIT_FAILURE);
        break;
        case 0:
            procPchild = getpid();
            printf("Figlio %d, padre %d\n", procPchild, getppid());
            for(size_t i = 0; i < 5000; i++){
            }
            printf("non dovrei arrivare qui!!\n");
            printf("Figlio %d, padre %d\n", procPchild, getppid());
        break;
        default:
            printf("Padre killed child\n");
            //sleep(1);
            kill(procPchild, SIGTERM);
            //wait(NULL);
            
        break;
    }
    exit(0);
    return 0;
}