#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    /*for (int i=0; i<3; i++){
        fork();
        printf("PID: %d, PPID: %d\n", getpid(), getppid());
    }*/

   /*for (int i=0; i<3; i++) {
        __pid_t n = fork();
        if(n == 0) printf("sono un figlio\n");
        else printf("sono un padre\n");
    }*/
   for (int i=0; i<3; i++) {
        __pid_t n = fork();
        if (n == 0) {
            printf("sono un figlio\n");
            exit(0);
        } else
            printf("sono un padre\n");   
    }
    return 0;
}