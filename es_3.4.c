#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


void creaproc(size_t n){
    __pid_t procid;
    int temp_att, i;
    for(i=0; i<n; i++ ){
        switch (procid = fork()){
            case -1:
                perror("Fork fallita");
                exit(EXIT_FAILURE);
            break;
            case 0:
                temp_att = getpid()%10;
                sleep(temp_att);
                exit(EXIT_SUCCESS);
            break;
        }
    }

    for(i=0; i<n; i++ ){
        printf("Sono il figlio %d\n", wait(NULL));
    }
    printf("Tutti i figli sono terminati\n");
    exit(EXIT_SUCCESS);
}

int main(){
    creaproc(3);
    return 0;
}