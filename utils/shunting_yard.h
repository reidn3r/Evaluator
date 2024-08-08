#ifndef SHUNTINGYARD_H
#define SHUNTINGYARD_H

#include "nodes.h"
#include "queue.h"
#include <stdbool.h>

enum operator_precedence {plus = 1, minus = 1, multiply = 2, divide = 2};

Queue* buildQueue(node *tokens);
bool isOperator(char *token);
bool isParentesis(char *token);
int operatorPrecedence(char operator);

#endif