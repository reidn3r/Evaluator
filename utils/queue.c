#include "queue.h"
#include "nodes.h"
#include <stdlib.h>
#include <stdio.h>

void initializeQueue(Queue *q){
    q -> first = NULL;
    q -> last = NULL;
    q -> size = 0;
}

void appendQueue(char *data, Queue *q){
    node *new_node = malloc(sizeof(node));
    new_node -> elem = data;
    new_node -> next = NULL;
    if(q -> first == NULL && q -> last == NULL){
        q -> first = new_node;
        q -> last = new_node;
    }
    else{
        q -> last -> next = new_node;
        q -> last = new_node;
    }
    q -> size = q -> size + 1;
}

void printQueue(Queue *q){
    node* head = q -> first;
    while(head != NULL){
        printf("%s ", head->elem);
        head = head -> next;
    }
}