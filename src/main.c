#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../utils/list.h"
#include "../utils/stack.h"
#include "../utils/queue.h"
#include "../utils/shunting_yard.h"

#include "../modules/lexer.h"
#include "../modules/parser.h"
#include "../modules/eval.h"
#include "../modules/tostring.h"

#define BUFFER_SIZE 255

int main(int argc, char** argv) {

    // Para avaliar tempo de execução
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    char buffer[BUFFER_SIZE];
    
    FILE* fd = fopen("io/input.txt", "r");
    if(fd == NULL) return 1;
    
    while(fgets(buffer, BUFFER_SIZE, fd)){
        node* tokens = string2tokens(buffer);
        // verificar parenteses:
        if(tokens == NULL) {
            fprintf(stderr, "Parênteses incorretos: %s\n", buffer);
            exit(EXIT_FAILURE);
        }

        Queue *q = buildQueue(tokens);

        tree_node* tree = parser(q);

        ToString* ts = ToString_create();
        //printf("> %s\n", to_expression(ts, tree, false);
        to_expression(ts, tree, false);

        while (eval(&tree) != 0) {

            //printf("> %s\n", to_expression(ts, tree, false);
            to_expression(ts, tree, false);
        }
        //printf("\n");
    }

    // Avalia tempo de execução
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\t[Testes executados em %d ms]\n", (int) (cpu_time_used*1000));

    return 0;
}