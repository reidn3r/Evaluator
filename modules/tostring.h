#ifndef TOSTRING_H
#define TOSTRING_H
#include "../utils/nodes.h"

typedef struct ToString {
    int precedence[256]; // Usando 256 para cobrir todos os caracteres possíveis
} ToString;

ToString* ToString_create();
char* to_expression(ToString* ts, tree_node* root, bool parentesis);

#endif