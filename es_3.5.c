#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void creaproc(size_t *arr, size_t n){
    __pid_t procid;
    size_t temp_att, i;
    for(i=0; i<n; i++ ){
        switch (procid = fork()){
            case -1:
                perror("Fork fallita");
                exit(EXIT_FAILURE);
            break;
            case 0:
                temp_att = arr[i];
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

    size_t n,i=0;
    printf("immettere numero figli:\t");
    scanf("%ld",&n);

    size_t arr_att[n];

    while(i<n){
        printf("immettere tempo per il figlio %ld: ", i+1);
        scanf("%ld",&arr_att[i]);
        i++;
    }

    creaproc(arr_att, n);
}