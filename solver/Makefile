##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Meilleur makefile
##

SRC =	src/base.c \
		src/loading_map.c \
		src/annexes.c \
		src/utils.c \
		src/number_maze.c \
		src/list_function.c \

OBJ =	$(SRC)

EXEC_NAME =	solver

GCC_ERROR_PARAM =	-W -Werror -Wextra -Wall -ansi -pedantic

GCC_PARAMS =	-g3

all : compile

compile :
	gcc $(SRC) -o $(EXEC_NAME) $(GCC_PARAMS)

spe :
	gcc $(SRC) -o $(EXEC_NAME) $(GCC_PARAMS) $(GCC_ERROR_PARAM)

exec :	compile
	./$(EXEC_NAME)

clean :
	rm -f $(EXEC_NAME)

fclean :	clean
	find . -type f \( -name "*~" -o \( -name "*#" -a -name "#*" \) \) -delete

re :	fclean all
