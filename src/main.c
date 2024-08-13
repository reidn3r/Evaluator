#include <stdio.h>
#include <stdlib.h>
#include "../utils/list.h"
#include "../utils/stack.h"
#include "../modules/lexer.h"
#include "../utils/queue.h"
#include "../utils/shunting_yard.h"
#include "../modules/parser.h"
#include "../modules/eval.h"

#define BUFFER_SIZE 255

int main(int argc, char** argv) {
    char buffer[BUFFER_SIZE];
    
    FILE* fd = fopen("io/input.txt", "r");
    if(fd == NULL) return 1;
    
    while(fgets(buffer, BUFFER_SIZE, fd)){
        printf("> %s\n", buffer);
        node* tokens = string2tokens(buffer);

        Queue *q = buildQueue(tokens);
        printf("queue: ");
        printQueue(q);
        printf("\n");

        tree_node* tree = parser(q);
        printf("in-order: ");
        inOrderTree(tree);
        printf("\n");

        eval(&tree);
        printf("evalued tree: ");
        inOrderTree(tree);
        printf("\n\n");
    }
    return 0;
}