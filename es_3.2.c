#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

__pid_t procPid;
int myvar;
int main(){
    switch(procPid = fork()){
        case -1:
            perror("Fork fallita");
            exit(EXIT_FAILURE);
            break;
        case 0:
            myvar = 10;
            break;
        default:
            //wait(NULL);
            myvar = myvar + 10;
            printf("SONO IL PADRE\n");
            break;
    }
    printf("%d\n", myvar);
    exit(EXIT_SUCCESS);
    return 0;
}