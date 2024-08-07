#include <stdio.h>
#include <stdlib.h>
#include "../utils/list.h"
#include "../utils/stack.h"
#include "../modules/lexer.h"

int main(int argc, char** argv) {
    node* list_tmp = NULL; // sempre nular os valores quando eles forem criados
    node* stack_tmp = NULL;

    char* str_test[] = {"reidner", "hudson", "padovani"};

    for(int i = 0, j = 2; i < 3 && j >= 0; i++, j--) {
        stackPush(str_test[i], &stack_tmp);
        listAppend(str_test[j], &list_tmp);
    }

    printf("Teste stack:\n");
    stackPrint(stack_tmp);
    printf("\n");

    printf("Teste list:\n");
    listPrint(list_tmp);
    printf("\n");

    printf("ultimo elemento da lista: %s\n", lastElem(list_tmp));

    listEmpty(&list_tmp);
    stackEmpty(&stack_tmp);

    // não printam nada pois a stack e a fila já estão vazias
    stackPrint(stack_tmp);
    listPrint(list_tmp);


    // Teste lexer
    printf("Teste lexer:\n");
    char* expression = "- 2 + 3 (4 / 8 - 5 * -(22 - 5))";

    node* tokens = string2tokens(expression);
    listPrint(tokens);
    listEmpty(&tokens);
    printf("\n");

    return 0;
}