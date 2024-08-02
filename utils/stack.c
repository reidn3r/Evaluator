#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

node* nodeCreate(char elem) {
    node* tmp = (node*)malloc(sizeof(node));
    tmp->elem = elem;
    tmp->next = NULL;
    
		if(tmp != NULL) {
			return tmp;
		}
		else {
			printf("Error in memory allocation");
			exit(EXIT_FAILURE);
		}
}

void stackPush(char elem, node** head) {
    if(*head == NULL) {
        *head = nodeCreate(elem);
        return;
    }
    
    node* tmp = nodeCreate(elem);
    tmp->next = *head;
    *head = tmp;
}

char stackPop(node** head) {
    if(*head == NULL) return '\0';
    
    char x = (**head).elem;
    node* tmp = *head;
    *head = (**head).next;
    free(tmp);
    
    return x;
}

void stackEmpty(node** head) {
    
    while(!isEmptyStack(*head))
        stackPop(head);
}

int isEmptyStack(node* head) {
    return (head == NULL);
}

void stackPrint(node* head) {
    if(head == NULL) return;
    if(head->next == NULL) {
        printf("%c -> ", head->elem);
        return;
    }
    
    stackPrint(head->next);
    printf("%c -> ", head->elem);
    return;
}