/*#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

static void dd_signal_handler(int signum){
    printf("Signal %d received\n", signum);
    signal(signum, SIG_DFL); // Restore default disposition
}

int main(){

    __pid_t procPid, procPchild;

    switch(procPid = fork()){
        case -1:
            perror("Fork fallita");
            exit(EXIT_FAILURE);
        break;
        case 0:
            for(size_t i = 0; i<5; i++){
                printf("%ld\n", i);
                sleep(1);
            }
        break;
        default:

            if(signal(SIGCHLD, dd_signal_handler) == SIG_ERR){
                perror("Impossibile attivare il segnale SIGCHLD");
                exit(EXIT_FAILURE);
            }
            if(signal(SIGINT, dd_signal_handler) == SIG_ERR){
                perror("Impossibile attivare il segnale SIGQUIT");
                exit(EXIT_FAILURE);
            }
            wait(NULL);
        break;
    }
    exit(0);
    return 0;
}*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>
//#include <asm/signal.h>

static void dd_signal_handler(int signum){
    printf("Got signal #%d: %s\n", signum, strsignal(signum));
}

int main(){

    __pid_t procPid;
    

    switch(procPid = fork()){
        case -1:
            perror("Fork fallita");
            exit(EXIT_FAILURE);
        break;
        case 0:
            sleep(2);
            for (size_t i=0; i<50; i++) {
                printf("Sleeping for 3 seconds\n");
                sleep(3);
            }
        break;
        default:
            struct sigaction sa;
            int i;
            sigset_t mask;
            sa.sa_handler = &dd_signal_handler;
            sigemptyset(&mask);
            sa.sa_mask = mask;
            sa.sa_flags = 0;
            for (i=0; i<NSIG; i++) { // set the handler for all signals
                if (sigaction(i, &sa, NULL) == -1) {
                    fprintf(stderr, "Cannot set a user-defined handler for Signal #%d: %s\n", i, strsignal(i));
                }
            }
            wait(NULL);
        break;
    }
    exit(0);
    return 0;
}
