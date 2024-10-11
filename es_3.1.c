#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

__pid_t procPid;
int main(){

    FILE *file;
    switch(procPid = fork()){
        case -1:
            perror("Fork fallita");
            exit(EXIT_FAILURE);
            break;
        case 0:
            file = fopen("es3.1.txt", "w");
            if(file == NULL){
                perror("Errore apertura file");
                exit(EXIT_FAILURE);
            }
            fputs("IL FIGLIO HA SCRITTO DENTRO IL FILE\n", file);
            fclose(file);
            break;
        default:
            //sleep(1);
            char buffer[50];
            file = fopen("es3.1.txt", "r");
            if(file == NULL){
                perror("Errore apertura file");
                exit(EXIT_FAILURE);
            }
            fgets(buffer, 50, file);
            printf("IL PADRE HA LETTO: %s\n", buffer);
            fclose(file);
            break;
    }
    return 0;
}