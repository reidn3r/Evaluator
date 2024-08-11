#ifndef NODES_H
#define NODES_H

// node é usado tanto para fila (list) quanto para pilha (stack)
typedef struct node node;
// tree_node será usado para a árvore, já que a struct é estruturada com dois ponteiros ao invés de um
typedef struct tree_node tree_node;

struct node {
    char* elem;
    tree_node* sub_tree; // finja que essa subtree sempre existiu dentro da struct e vocês só ignoraram quando usavam esse nó
    node* next;
};

struct tree_node {
    char* elem;
    tree_node* left;
    tree_node* right;
    tree_node* next;
};

#endif

