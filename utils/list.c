#include <stdio.h> //NULL
#include <stdlib.h> // malloc e free
#include "list.h"


bool isEmpty(node* node) {
    return node == NULL;
}

void listAppend(char elem, node** list) {
    if(isEmpty(*list)) {
        *list = (node*) malloc(sizeof(node));
        (*list)->elem = elem;
        (*list)->next = NULL;

        return;
    }

    listAppend(elem , &((*list)->next));
}

char listPop(node** list) {
    if(!isEmpty(*list)) {
        char elem = (*list)->elem;

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
    node* tmp;
    while(*list != NULL) {
        tmp = *list;
        *list = (*list)->next;
        free(tmp);        
    }
}

void listPrint(node* list) {
    if(list != NULL) {
        printf("%c -> ", list->elem);
        listPrint(list->next);
    }

    return;

}