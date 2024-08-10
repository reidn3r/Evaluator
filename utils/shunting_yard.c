#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "shunting_yard.h"
#include "nodes.h"
#include "queue.h"
#include "stack.h"

Queue* buildQueue(node *tokens){
    Queue *queue = malloc(sizeof(Queue));
    initializeQueue(queue);

    node *stack_operator = NULL;

    node *current_token = tokens;
    while(current_token != NULL){
        char *token = current_token -> elem;

        if(!isOperator(token) && !isParentesis(token)){
            //Não é operador nem parenteses, enfileira o operando
            appendQueue(token, queue);
        }

        else if(isOperator(token)) {
            //Processa operador
            while (stackSize(stack_operator) > 0 && 
                isOperator(stackTopElement(stack_operator)) &&
                operatorPrecedence(stackTopElement(stack_operator)) >= operatorPrecedence(token)) {
                    char *stack_top_element = stackPop(&stack_operator);
                    appendQueue(stack_top_element, queue);
            }
            stackPush(token, &stack_operator);
        }

        else if(strcmp(token, "(") == 0){
            //Add. ( na pilha
            stackPush(token, &stack_operator);
        }

        else if(strcmp(token, ")") == 0){
            //Enquanto não encontra (, enfileira operandos e operadores
            while(stackSize(stack_operator) > 0 && strcmp(stackTopElement(stack_operator), "(") != 0){
                char *stack_top_element = stackPop(&stack_operator);
                appendQueue(stack_top_element, queue);
            }
            stackPop(&stack_operator); // Remove o '(' da pilha
        }

        current_token = current_token -> next;
    }

    while(stackSize(stack_operator) > 0){
        //Esvazia pilha de operadores, enfileirando todos eles
        char *stack_top_element = stackPop(&stack_operator);
        appendQueue(stack_top_element, queue);
    }
    
    return queue;
}

bool isOperator(char *token) {
    if (strlen(token) != 1) {
        return false;
    }

    return strcmp(token, "+") == 0 ||
        strcmp(token, "-") == 0 ||
        strcmp(token, "*") == 0 ||
        strcmp(token, "/") == 0;
}

bool isParentesis(char *token) {
    if (strlen(token) != 1) {
        return false;
    }

    return strcmp(token, "(") == 0 || strcmp(token, ")") == 0;
}

int operatorPrecedence(char *operator) {
    if(strcmp(operator, "+") == 0 || strcmp(operator, "-") == 0){
        return 1;
    }
    if(strcmp(operator, "*") == 0 || strcmp(operator, "/") == 0){
        return 2;
    }
    return 0;
}
