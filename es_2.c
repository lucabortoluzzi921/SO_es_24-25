#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


// ------------ IMPLEMENTAZIONE -------------

char** leggi_lista(FILE* file_in, int* nof_elements) {
    char *nome_file = "lista_nomi.txt";
    
    FILE *file_temp = fopen(nome_file, "r");

    if(file_temp == NULL){
        perror("Errore apertura file!!\n");
        return NULL;
    }
    
    int ch;
    int num_nomi_temp = 0;
    while(!feof(file_temp)){
        ch = getc(file_temp);

        if(ch == '\n'){
            num_nomi_temp++;
        }
    }
    num_nomi_temp++;
    *nof_elements = num_nomi_temp;
}

void stampa_lista(char** mio_ar, int n_elems) {
    int i;
    for(i=0; i<n_elems; i++){
        fprintf();
    }
}

int main(int argc, char** argv) {
    FILE *file;
    int num_nomi;
// CHIAMATA alla funzione leggi_lista()
    leggi_lista(file, &num_nomi);
// CHIAMATA alla funzione stampa_lista()
    printf("%d\n", num_nomi);

    return 0;
}

// PRE: il numero di righe del file corrisponde
// esattamente al numero degli elementi
