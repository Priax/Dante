##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Dante
##

NAME = Dante

all:
		chmod 777 tester.sh
		cd generator/ && make spe
		cd solver/ && make

W_FLAG = -W -Wall -Wextra -g3

LAST_FLAG = -Werror -ansi -pedantic

FLAG_VAL = --tool=memcheck --leak-check=yes --show-reachable=yes

FLAG_VAL2 = --leak-check=full --show-leak-kinds=all --track-origins=yes -s

style:	fclean
	coding-style . .
	cat coding-style-reports.log

val: $(NAME)
	valgrind ./$(NAME)

push:	fclean
	git add .
	echo git commit -m ""
	echo git push

clean:
		rm -f coding-style-reports.log

fclean: clean
		rm -f generator/generator
		rm -f solver/solver

re:		fclean all

.PHONY:	all fclean clean re
