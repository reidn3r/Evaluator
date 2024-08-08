#ifndef SHUNTINGYARD_H
#define SHUNTINGYARD_H

#include "nodes.h"
#include "queue.h"
#include <stdbool.h>

Queue* buildQueue(node *tokens);
bool isOperator(char *token);
bool isParentesis(char *token);
int operatorPrecedence(char* operator);

#endif