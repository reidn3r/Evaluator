#include <stdio.h>
#include <stdlib.h>
#include "../utils/list.h"

int main(int argc, char** argv) {
    node* tmp = NULL; // sempre nular os valores quando eles forem criados
    
    char line[2];
    printf("type a value: ");
    if(fgets(line, sizeof(line), stdin) == NULL) {
        printf("input error.\n");
        exit(1);
    }

    char elem = line[0];
    listAppend(elem, &tmp);
    listAppend('b', &tmp);
    listAppend(elem, &tmp);
    listAppend('c', &tmp);
    listAppend(elem, &tmp);
    listAppend('d', &tmp);
    listPrint(tmp);
    listEmpty(&tmp);
    return 0;
}