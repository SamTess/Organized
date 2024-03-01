##
## EPITECH PROJECT, 2023
## B-PSU-100
## File description:
## Organized : Makefile
##

SRC		=	$(shell find . -type f -name '*.c')

OBJ 	=	$(SRC:.c=.o)

NAME	=	libmy.a

NAME_EXEC	=	organized

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	gcc -o $(NAME_EXEC) $(SRC) libmy.a libshell.a -Wall -Wextra

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(OBJ)
	rm -f $(NAME_EXEC)
	rm -f coding-style-reports.log

re:	fclean all
