#include <string.h>
#include <stdlib.h>
#include "copy.h"
/*Módulo de funções auxiliares e úteis*/

// copia a string em 'elem' para 'dest' tirando os espaços em branco
void copy(char** dest, char* elem) {
    int elem_length = strlen(elem);
    int dest_elem = 0;
    *dest = malloc(sizeof(char)*(elem_length+1));

    for(int i = 0; i<elem_length; i++) {
        if(elem[i] != ' '){
            (*dest)[dest_elem] = elem[i];
            dest_elem++;
        }
    }

    (*dest)[dest_elem] = '\0';
}