#ifndef PARSER_H
#define PARSER_H
#include "../utils/nodes.h"
#include "../utils/queue.h"

tree_node* parser(Queue* q);
tree_node* treeHandling(node** stack, char* op);
// tree_node* build(tree_node* stack, tree_node* stack_base);
tree_node* build(tree_node* root);
void inOrderTree(tree_node* tree);

#endif