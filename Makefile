.SILENT:

EXE_NAME=-o a.exe
MAIN=src/main.c
UTILS=$(wildcard utils/*.c)
MODULES=$(wildcard modules/*.c)
FLAGS=-Wall -Wextra
DEBUG=-g

.PHONY:

# digite apenas 'make' na mesma pasta onde está o arquivo 'makefile' para compilar o projeto todo
# gcc $(MAIN) $(UTILS) $(MODULES) $(FLAGS)
std:
	gcc $(MAIN) $(UTILS) $(MODULES) $(EXE_NAME)


# compilações para testes caso precisemos:
# digite 'make ut' para compilar sem os arquivos da pasta modules
ut:
	gcc $(MAIN) $(UTILS) $(EXE_NAME)

# digite 'make md' para compilar sem os arquivos da pasta utils
md:
	gcc $(MAIN) $(MODULES) $(EXE_NAME)

gdb:
	gcc $(MAIN) $(UTILS) $(MODULES) $(DEBUG) $(EXE_NAME)
