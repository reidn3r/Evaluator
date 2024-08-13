#ifndef EVAL_H
#define EVAL_H

void eval(tree_node** root);
void setNumber(tree_node** root, int result);
int valueOperate(char* left, char* right, char* op);
bool isNumber(char* number);


#endif