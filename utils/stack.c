#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "copy.h"
#include "../modules/parser.h"

node* nodeCreate(char* elem) {
    node* tmp = (node*)malloc(sizeof(node));
    // tmp->elem = elem;
    copy(&(tmp->elem), elem);
    tmp->next = NULL;
    tmp->sub_tree = NULL;
    
		if(!isEmptyStack(tmp)) {
			return tmp;
		}
		else {
			printf("Error in memory allocation");
			exit(EXIT_FAILURE);
		}
}

void stackPush(char* elem, node** head) {
    if(isEmptyStack(*head)) {
        *head = nodeCreate(elem);
        return;
    }
    
    node* tmp = nodeCreate(elem);
    tmp->next = *head;
    *head = tmp;
}

// caso especial de push na stack, onde uma sub-àrvore é colocada no topo da stack
// void stackPushTree(tree_node* sub_tree, node** head) {
//     if(isEmptyStack(*head)) {
//         *head = (node*)malloc(sizeof(node));
//         (*head)->elem = '\0';
//         (*head)->sub_tree = sub_tree;
//         (*head)->next = NULL;
//         return;
//     }

//     node* tmp = (node*)malloc(sizeof(node));
//     tmp->elem = '\0';
//     tmp->sub_tree = sub_tree;
//     tmp->next = *head;
//     *head = tmp;
// }


char* stackPop(node** head) {
    if(isEmptyStack(*head)) return '\0';
    
    char* x = (**head).elem;
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
    if(isEmptyStack(head)) return;
    if(isEmptyStack(head->next)) {
        if(head->elem != NULL) {
            printf("%s -> ", head->elem);
        } else {
            inOrderTree(head->sub_tree);
            printf("-> ");
        }
        return;
    }
    

    stackPrint(head->next);
    if(head->elem != NULL) {
            printf("%s -> ", head->elem);
        } else {
            inOrderTree(head->sub_tree);
            printf("-> ");
        }
    return;
}

int stackSize(node *head){
    if(isEmptyStack(head)) return 0;

    int size = 1;
    while(!isEmptyStack(head)){
        head = head -> next;
        size++;
    }
    return size;
}

char *stackTopElement(node *head){
    if(isEmptyStack(head)) return NULL;
    return head -> elem;
}


tree_node* stackPushSubTree(tree_node* sub_tree, tree_node* stack_top){
    sub_tree -> next = stack_top;
    return sub_tree;
}

tree_node* stackPopSubTree(tree_node** stack_top){
    if(stack_top == NULL) return NULL;

    tree_node* output_node = *stack_top;
    *stack_top = (*stack_top) -> next;

    return output_node;
}