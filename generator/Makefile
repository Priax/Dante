##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Dante
##

SRC	=	src/randomized_backtracker.c \
		src/utils.c \
		src/my_strcmp.c \
		src/cat.c \
		src/dante_utils.c \
		src/grid.c \
		src/generating_maze.c \


OBJ	=	$(SRC:.c=.o)

NAME = generator

all:	$(NAME)

W_FLAG = -W -Wall -Wextra -g3

LAST_FLAG = -Werror -ansi -pedantic

FLAG_VAL = --tool=memcheck --leak-check=yes --show-reachable=yes

FLAG_VAL2 = --leak-check=full --show-leak-kinds=all -s

$(NAME):
		gcc $(SRC) $(W_FLAG) -I include -o $(NAME) -g -lm

style:	fclean
	coding-style . .
	cat coding-style-reports.log

spe:
	gcc $(SRC) $(W_FLAG) $(LAST_FLAG) -I include -o $(NAME) -g -lm

val: $(NAME)
	valgrind $(FLAG_VAL) $(FLAG_VAL2) ./$(NAME)

push:	fclean
	git add .
	echo git commit -m ""
	echo git push

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)
re:		fclean all

.PHONY:	all fclean clean re
