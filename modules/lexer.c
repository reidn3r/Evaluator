#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "../utils/list.h"

// Função para verificar se um caractere é um espaço em branco
bool is_whitespace(char c) {
    return isspace(c);
}

// Função para verificar se um caractere é um dígito
bool is_digit(char c) {
    return isdigit(c);
}

// Função para verificar se um caractere é um operador aritmético
bool is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Função para analisar a string e retornar uma lista de tokens
node* string2tokens(const char* string) {
    node* tokens = NULL;
    int current_position = 0;
    int length = strlen(string);

    while (current_position < length) {
        char current_char = string[current_position];

        if (is_whitespace(current_char)) {
            // Ignora espaços em branco e avança para o próximo caractere
            current_position++;
            continue;
        }

        // Um número inteiro pode ser positivo ou negativo
        // Para se reconhecer um número negativo, primeiro verifica-se se o caractere atual é '-'
        // Se for o caso, temos duas possibilidades de ser um número negativo: ser o começo da expressão ou o token anterior ser '+-*/('
        // Para o segundo caso, verifica-se se existem tokens, se o último adicionado foi um caractere, e se pertence a '+-*/(' respectivamente
        if (is_digit(current_char) || (current_char == '-' && ( // TODO: não reconhece números negativos corretamente
                current_position == 0 || 
                (!isEmpty(tokens) && is_operator(tokens->elem) || tokens->elem == '(')))) {
            // Reconhece números inteiros e números negativos
            int start_position = current_position;
            if (current_char == '-') {
                current_position++;
            }

            while (current_position < length && is_digit(string[current_position])) {
                current_position++;
            }

            char num_str[12]; // Buffer para armazenar o número como string (considerando um int de 32 bits)

            // Copia o número da string para o buffer
            strncpy(num_str, string + start_position, current_position - start_position);
            num_str[current_position - start_position] = '\0';

            listAppend(atoi(num_str), &tokens); // TODO: atualmente converte pra int, mesmo que a função não seja capaz de receber um int

        } else if (is_operator(current_char)) {
            // Reconhece operadores aritméticos
            listAppend(current_char, &tokens);
            current_position++;
        } else if (current_char == '(' || current_char == ')') {
            // Reconhece parênteses
            listAppend(current_char, &tokens);
            current_position++;
        } else {
            // Levanta uma exceção para caracteres inesperados
            fprintf(stderr, "Caractere inesperado: %c\n", current_char);
            exit(EXIT_FAILURE);
        }
    }

    return tokens;
}