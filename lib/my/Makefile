##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

SRC	=	clone.c		\
		list_create.c		\
		list_destroy.c		\
		list_utils.c		\
		print_dbl_tab.c 	\
		string_cutter/concatainer.c 	\
		string_cutter/str_utils.c 	\
		string_cutter/string_cutter.c


OBJ	=	$(SRC:.c=.o)

CFLAGS 	= 	-I../../include/

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		cp $(NAME) ../../build/$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
