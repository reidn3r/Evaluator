#include <stdio.h>
#include <stdlib.h>
#include "../utils/list.h"
#include "../utils/stack.h"
#include "../modules/lexer.h"

int main(int argc, char** argv) {
    node* list_tmp = NULL; // sempre nular os valores quando eles forem criados
    node* stack_tmp = NULL;

    for(char i = 97, j = 107; i <= 107 && j >= 97; i++ && j--) {
        stackPush(i, &stack_tmp);
        listAppend(j, &list_tmp);
    }

    printf("Teste stack:\n");
    stackPrint(stack_tmp);
    printf("\n");

    printf("Teste list:\n");
    listPrint(list_tmp);
    printf("\n");

    listEmpty(&list_tmp);
    stackEmpty(&stack_tmp);

    // não printam nada pois a stack e a fila já estão vazias
    stackPrint(stack_tmp);
    listPrint(list_tmp);

    // Teste lexer
    printf("Teste lexer:\n");
    const char* expression = "3+4*(5 - 6)";

    node* tokens = string2tokens(expression);
    listPrint(tokens);
    listEmpty(&tokens);

    return 0;
}