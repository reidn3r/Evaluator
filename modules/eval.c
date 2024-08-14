#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "../utils/nodes.h"
#include "eval.h"
#include "../utils/nodes.h"
#include "lexer.h"
#include "../utils/copy.h"

int eval(tree_node** root) {
    
    if((*root)->left == NULL && (*root)->right == NULL && isNumber((*root)->elem)) return 0; 

    if(!isNumber((*root)->left->elem)) {
        eval(&((*root)->left));
    } else if(!isNumber((*root)->right->elem)) {
        eval(&((*root)->right));
    } else if(!isNumber((*root)->elem)){
        long long result = valueOperate((*root)->left->elem, (*root)->right->elem, (*root)->elem);
        setNumber(root, result);
    }

    return 1;
}

long long valueOperate(char* left, char* right, char* op) {
    long long left_num = atoi(left);
    long long right_num = atoi(right);

    switch(op[0]) {
        case '+':
            return left_num + right_num;
            break;
        case '-':
            return left_num - right_num;
            break;
        case '*':
            return left_num * right_num;
            break;
        case '/':
            return left_num / right_num;
            break;
        default:
            printf("undefined operator.\n");
    }

}

void setNumber(tree_node** root, long long result) {
    char str_result[20];
    sprintf(str_result, "%lld", result);

    copy(&((*root)->elem), str_result);

    free((*root)->left);
    (*root)->left = NULL;
    free((*root)->right);
    (*root)->right = NULL;
}

bool isNumber(char* number) {
    int len = strlen(number);
    int i = 0;
    if(number[0] == '-' && len != 1) {
        i = 1;
    } else if(is_digit(number[0])){
        i = 0;
    }
    while(i < len) {
        if(!is_digit(number[i])) return false;
        i++;
    } 

    return true;

}

