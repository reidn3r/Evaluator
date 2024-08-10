#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "../utils/queue.h"
#include "../utils/nodes.h"
#include "../utils/list.h"
#include "../utils/shunting_yard.h"
#include "../utils/stack.h"
#include "../utils/copy.h"

tree_node* parser(Queue* q) {
    node* head = q->first;
    node* stack = NULL;
    tree_node* tmp;

    while(!isEmpty(head)) {

        if(!isOperator(head->elem)) {
            stackPush(head->elem, &stack);

        } else {
            stackPushTree(treeHandling(&stack, head->elem), &stack);
        }

        head = head->next;
    }

    inOrderTree(stack->sub_tree);

    return !isEmptyStack(stack) ? stack->sub_tree : NULL;

}

tree_node* treeHandling(node** stack, char* op) {
    tree_node* tmp = (tree_node*)malloc(sizeof(tree_node));
    tree_node* sub_right = NULL;
    tree_node* sub_left = NULL;
    tmp->elem = op;

    // verifica se o elemento do topo é um número ou uma sub-àrvore
    if((*stack)->elem != NULL) { // é um número
        char* right = stackPop(stack);

        sub_right = (tree_node*)malloc(sizeof(tree_node));
        copy(&(sub_right->elem), right);
        sub_right->left = NULL;
        sub_right->right = NULL;

    } else { // é uma sub-àrvore
        sub_right = (*stack)->sub_tree;
        stackPop(stack);

    }

    tmp->right = sub_right;

    // verifica se o elemento abaixo do elemento do topo é um número ou uma sub-àrvore
    if((*stack)->elem != NULL) { // é um número
        char* left = stackPop(stack);

        sub_left = (tree_node*)malloc(sizeof(tree_node));
        copy(&(sub_left->elem), left);
        sub_left->left = NULL;
        sub_left->right = NULL;
    } else { // é uma sub-àrvore
        sub_left = (*stack)->sub_tree;
        stackPop(stack);

    }


    tmp->left = sub_left;

    return tmp;
}

void inOrderTree(tree_node* tree) {
    if(tree->left != NULL) {
        inOrderTree(tree->left);
    }

    printf("%s ", tree->elem);

    if(tree->right != NULL) {
        inOrderTree(tree->right);
    }
}