##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile
##

CC	=	gcc

SRC	=	src/lecture.c			\
		src/my_getnbr.c			\
		src/my_putchar.c		\
		src/my_put_nbr.c		\
		src/algo.c			\
		src/my_putstr.c			\
		src/my_strlen.c		

OBJ	=	$(SRC:.c=.o)

NAME	=	bsq

.SILENT:

$(NAME):	$(OBJ)
	$(CC)  -o $(NAME) $(OBJ)
		@echo "Compilation faite!"

all:	$(NAME)

clean:
	rm -f $(OBJ)
		@echo "Clean faite!"

fclean: clean
	rm -f $(NAME)
		@echo "FClean faite!"

re:	fclean all
		@echo "Re fait!"

.PHONY: clean fclean re all
