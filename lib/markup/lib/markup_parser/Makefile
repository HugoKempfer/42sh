##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Standard Makefile configuration
##

SILENT_MODE =	TRUE

SRC =	src/data_struct.c		\
	src/file_parser.c		\
	src/file_to_buffer.c		\
	src/tree_explorer.c		\
	src/tree_free.c			\
	src/lexer/array_lexer.c		\
	src/lexer/lexer_free.c		\
	src/strings/strings.c		\

OBJ =	$(SRC:.c=.o)

NAME =	libmarkup_parser.a

AR =	ar rc

RM =	rm -f

CFLAGS =	-Wall -Wextra -I./include/

ifeq ($(SILENT_MODE), TRUE)
.SILENT:
endif

all:	$(NAME)

$(NAME):	$(OBJ)
	$(AR) $(NAME) $(OBJ)
	@echo "Markup parser library built"
	cp include/markup.h ../.././include/
	cp libmarkup_parser.a ../../build/

clean:
	$(RM) $(OBJ)
	@echo "Clean done !"

fclean:	clean
	$(RM) $(NAME)
	rm ../../include/markup.h
	rm ../../build/libmarkup_parser.a
	@echo "Fclean done !"

re: fclean all
