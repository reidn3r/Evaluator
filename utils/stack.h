#ifndef STACK_H
#define STACK_H

#include "nodes.h"

node* nodeCreate(char* elem);
void stackPush(char* elem, node** head);
char* stackPop(node** head);
void stackEmpty(node** head);
int isEmptyStack(node* head);
void stackPrint(node* head);
void stackPushTree(tree_node* sub_tree, node** head);

char *stackTopElement(node *head);
int stackSize(node *head);
#endif