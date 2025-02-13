#ifndef LEXER_H
#define LEXER_H

#include "../utils/nodes.h"

// Função para analisar a string e retornar uma lista de tokens
node* string2tokens(const char* string);
bool is_digit(char c);
bool evalTokens(node* tokens);

#endif