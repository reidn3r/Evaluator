#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "../utils/nodes.h"

typedef struct ToString {
    int precedence[256]; // Usando 256 para cobrir todos os caracteres possíveis
} ToString;

ToString* ToString_create() {
    ToString* ts = (ToString*)malloc(sizeof(ToString));

    // Não se assuste, o que importa é que funciona
    ts->precedence['+'] = 1;
    ts->precedence['-'] = 1;
    ts->precedence['*'] = 2;
    ts->precedence['/'] = 2;
    return ts;
}

bool is_int_string(const char* str) {

    if (*str == '\0' || !strcmp(str, "-")) {
        return false; // String vazia não é um inteiro e operador '-' não são inteiros
    }

    // Se o primeiro caractere for um sinal de negativo, avança o ponteiro
    if (*str == '-') {
        str++;
    }

    // Verifica se cada caractere é um dígito
    while (*str) {
        if (!isdigit(*str)) {
            return false;
        }
        str++;
    }
    return true;
}

char* to_expression(ToString* ts, tree_node* root, bool parentesis) {
    
    if (root == NULL) {
        return "";
    }

    // Se o nó é uma folha, retorna o valor do nó
    if (root->left == NULL || root->right == NULL) {
        return root->elem;
    }

    // Verifica se a precedência da operação do nó inferior é menor, logo a expressão necessita de parênteses

    char* left_expr;
    if (!is_int_string(root->left->elem) && // Verifica antes se não é um operando 
        ts->precedence[(int)root->left->elem[0]] < ts->precedence[(int)root->elem[0]]) {

        left_expr = to_expression(ts, root->left, true);
    } else {
        left_expr = to_expression(ts, root->left, false);
    }

    char* right_expr;
    if (!is_int_string(root->right->elem) && // Verifica antes se não é um operando 
        ts->precedence[(int)root->right->elem[0]] < ts->precedence[(int)root->elem[0]]) {
        right_expr = to_expression(ts, root->right, true);
    } else {
        right_expr = to_expression(ts, root->right, false);
    }

    // Para calcular o tamanho da string resultante
    int expr_len;
    char* result;

    // printf("-->[%s][%s][%s][%d]\n", left_expr, root->elem, right_expr, parentesis);

    if (parentesis) {
        expr_len = strlen(left_expr) + strlen(root->elem) + strlen(right_expr) + 5; // +2 para os espaços +1 terminador nulo +2 parenteses = 5
        result = (char*)malloc(expr_len * sizeof(char));

        snprintf(result, expr_len, "(%s %s %s)", left_expr, root->elem, right_expr);
    } else {
        expr_len = strlen(left_expr) + strlen(root->elem) + strlen(right_expr) + 3; // +2 para os espaços +1 terminador nulo = 3
        result = (char*)malloc(expr_len * sizeof(char));

        snprintf(result, expr_len, "%s %s %s", left_expr, root->elem, right_expr);
    }

    return result;
}
