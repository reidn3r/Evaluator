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
    tree_node* stack = NULL;
    
    while(head != NULL) {
        if(!isOperator(head->elem)) {
            tree_node* node = (tree_node*)malloc(sizeof(tree_node));
            node -> elem = head -> elem;
            node->left = node->right = node->next = NULL;
            stack = stackPushSubTree(node, stack);
        } 
        else {
            tree_node* sub_tree = (tree_node*)malloc(sizeof(tree_node));
            sub_tree -> elem = head -> elem;
            sub_tree -> left = sub_tree -> right = sub_tree -> next = NULL;

            tree_node* right_data = stackPopSubTree(&stack);
            sub_tree -> right = right_data;
            
            tree_node* left_data = stackPopSubTree(&stack);
            sub_tree -> left = left_data;

            stack = stackPushSubTree(sub_tree, stack);
        }
        head = head->next;
    }

    stack = build(stack);
    return stack;
}

tree_node* build(tree_node* root){
    // tree_node* prev_node = root;
    // tree_node* next_node = prev_node -> next;
    // while(next_node != NULL){
    //     next_node -> left = prev_node;
    //     prev_node = next_node;
    //     next_node = prev_node -> next;
    // }
    // return prev_node;

    if(root -> next == NULL){
        return root;
    }
    else{
        tree_node* node = build(root -> next);
        node -> left = root;
        return node;
    }
}

// tree_node* treeHandling(node** stack, char* op) {
//     tree_node* tmp = (tree_node*)malloc(sizeof(tree_node));
//     tree_node* sub_right = NULL;
//     tree_node* sub_left = NULL;
//     tmp->elem = op;

//     // verifica se o elemento do topo é um número ou uma sub-àrvore
//     if((*stack)->elem != NULL) { // é um número
//         char* right = stackPop(stack);

//         sub_right = (tree_node*)malloc(sizeof(tree_node));
//         copy(&(sub_right->elem), right);
//         sub_right->left = NULL;
//         sub_right->right = NULL;

//     } else { // é uma sub-àrvore
//         sub_right = (*stack)->sub_tree;
//         stackPop(stack);

//     }

//     tmp->right = sub_right;

//     // verifica se o elemento abaixo do elemento do topo é um número ou uma sub-àrvore
//     if((*stack)->elem != NULL) { // é um número
//         char* left = stackPop(stack);

//         sub_left = (tree_node*)malloc(sizeof(tree_node));
//         copy(&(sub_left->elem), left);
//         sub_left->left = NULL;
//         sub_left->right = NULL;
//     } else { // é uma sub-àrvore
//         sub_left = (*stack)->sub_tree;
//         stackPop(stack);

//     }


//     tmp->left = sub_left;

//     return tmp;
// }

void inOrderTree(tree_node* tree) {
    if(tree->left != NULL) {
        inOrderTree(tree->left);
    }

    printf("%s ", tree->elem);

    if(tree->right != NULL) {
        inOrderTree(tree->right);
    }
}