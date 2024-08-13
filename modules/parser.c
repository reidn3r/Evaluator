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
    if(root -> next == NULL){
        return root;
    }
    else{
        tree_node* node = build(root -> next);
        node -> left = root;
        return node;
    }
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
