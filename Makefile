.SILENT:

EXE_NAME=-o main
MAIN=src/main.c
UTILS=$(wildcard utils/*.c)
MODULES=$(wildcard modules/*.c)
FLAGS=-Wall -Wextra
DEBUG=-g

.PHONY:

# digite apenas 'make' na mesma pasta onde está o arquivo 'makefile' para compilar o projeto todo
std:
	gcc $(MAIN) $(UTILS) $(MODULES) # $(FLAGS)


# compilações para testes caso precisemos:
# digite 'make ut' para compilar sem os arquivos da pasta modules
ut:
	gcc $(MAIN) $(UTILS)

# digite 'make md' para compilar sem os arquivos da pasta utils
md:
	gcc $(MAIN) $(MODULES)

gdb:
	gcc $(MAIN) $(UTILS) $(MODULES) $(DEBUG)
