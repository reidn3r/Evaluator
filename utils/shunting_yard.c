#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "shunting_yard.h"
#include "nodes.h"
#include "queue.h"
#include "stack.h"
#include "string.h"

Queue* buildQueue(node *tokens){
    Queue *queue = malloc(sizeof(Queue));
    initializeQueue(queue);

    node *stack_operator = NULL;

    node *current_token = tokens;
    while(current_token != NULL){
        char *token = current_token -> elem;

        if(!isOperator(token) && !isParentesis(token)){
            appendQueue(token, queue);
        }

        else if(isOperator(token)){
            char *stack_top_element = stackTopElement(stack_operator);
            while(stackSize(stack_operator) > 0 &&
                    operatorPrecedence(*stack_top_element) >= operatorPrecedence(*token) &&
                    strcmp(stack_top_element, "(") != 0){
                stack_top_element = stackPop(&stack_operator);
                appendQueue(stack_top_element, queue);
            }
            stackPush(token, &stack_operator);
        }

        else if(strcmp(token, "(") == 0){
            stackPush(token, &stack_operator);
        }

        else if(strcmp(token, ")") == 0){
            char *stack_top_element = stackTopElement(stack_operator);
            while(stackSize(stack_operator) > 0 && strcmp(stack_top_element, "(") != 0){
                stack_top_element = stackPop(&stack_operator);
                appendQueue(stack_top_element, queue);
            }
            stack_top_element = stackPop(&stack_operator);
        }

        current_token = current_token -> next;
    }
    while(stackSize(stack_operator) > 0){
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

int operatorPrecedence(char operator) {
    if(strcmp(operator, "+") == 0 || strcmp(operator, "-")){
        return 1;
    }
    if(strcmp(operator, "*") == 0 || strcmp(operator, "/")){
        return 2;
    }
    return 0;
}
