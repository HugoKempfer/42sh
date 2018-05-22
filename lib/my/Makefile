##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## make my lib
##

SRC	=	my_putstr.c	\
		my_putchar.c	\
		my_strcat.c	\
		my_strlen.c	\
		is_alpha_num_2d.c	\
		my_str_custcat.c	\
		my_putnchar.c	\
		my_putnbr.c	\
		my_strcmp.c	\
		my_strcpy.c	\
		len.c		\
		my_strcmp_key.c	\
		clone.c	\
		my_strncmp.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

AR	=	ar rc

all:		$(NAME)

$(NAME):	$(OBJ)
		$(AR) $(NAME) $(OBJ)
		cp my.h ../../include
		cp list.h ../../include

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

auteur:
		echo $(USER) > auteur

re: 		fclean all
