#ifndef EVAL_H
#define EVAL_H

int eval(tree_node** root);
void setNumber(tree_node** root, long long result);
long long valueOperate(char* left, char* right, char* op);
bool isNumber(char* number);


#endif