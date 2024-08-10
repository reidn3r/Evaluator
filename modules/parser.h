#ifndef PARSER_H
#define PARSER_H
#include "../utils/nodes.h"
#include "../utils/queue.h"

tree_node* parser(Queue* q);
tree_node* treeHandling(node** stack, char* op);
void inOrderTree(tree_node* tree);

#endif