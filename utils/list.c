#include <stdio.h> //NULL
#include <stdlib.h> // malloc e free
#include <string.h>
#include "list.h"
#include "copy.h"

bool isEmpty(node* node) {
    return node == NULL;
}

void listAppend(char* elem, node** list) {
    if(isEmpty(*list)) {
        *list = (node*) malloc(sizeof(node));
        // (*list)->elem = elem;
        copy(&((*list)->elem), elem);
        (*list)->next = NULL;
        return;
    }

    listAppend(elem , &((*list)->next));
}

char* listPop(node** list) {
    if(!isEmpty(*list)) {
        char* elem = (*list)->elem;

        node* tmp = *list;
        (*list) = (*list)->next;
        free(tmp);

        return elem;
    } else {
        return '\0'; // TODO: achar uma forma melhor de dizer que a lista ta vazia :)
    }
}

// não confundir essa função com a função isEmpty, essa é pra esvaziar a lista toda.
void listEmpty(node** list) {
    while(!isEmpty(*list)) {
        listPop(list);        
    }
}

void listPrint(node* list) {
    if(!isEmpty(list)) {
        printf(" %s ->", list->elem);
        listPrint(list->next);
    }

    return;

}

char* lastElem(node* list) {
    if(!isEmpty(list) && !isEmpty(list->next)) {
        return lastElem(list->next);
    }

    return list != NULL ? list->elem : '\0';
}