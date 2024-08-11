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

tree_node* stackPushSubTree(tree_node* sub_tree, tree_node* stack_top);
tree_node* stackPopSubTree(tree_node** stack_top);

char *stackTopElement(node *head);
int stackSize(node *head);
#endif