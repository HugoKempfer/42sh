##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Standard Makefile configuration
##

SRC	=	$(wildcard src/*.c) $(wildcard ./src/*/*.c) $(wildcard src/*/*/*.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	42sh

GCC	=	gcc

ifneq		(,$(wildcard ./debug))
CFLAGS	=	-ggdb3 -pedantic -Wduplicated-cond \
		-Wduplicated-branches -Wlogical-op -Wrestrict \
		-Wnull-dereference -Wjump-misses-init -Wdouble-promotion \
		-Wshadow -Wformat=2 -fno-omit-frame-pointer

LDFLAGS	=	-fno-omit-frame-pointer
endif

ifneq		(,$(wildcard ./valgrind_mod))
CFLAGS	=	-g -pedantic -Wduplicated-cond \
		-Wduplicated-branches -Wlogical-op -Wrestrict \
		-Wnull-dereference -Wjump-misses-init -Wdouble-promotion \
		-Wshadow -Wformat=2 -fno-omit-frame-pointer

LDFLAGS	=	-fno-omit-frame-pointer
endif

CFLAGS	+=	-I./include/

LDFLAGS	+=	-L./lib/my/ -lmy -lm -L./lib/markup/build/ -lmarkup_parser

.SILENT:

$(NAME):	libmy $(OBJ) libjson $(OBJ)
		$(GCC) -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS)

libmy:
		$(MAKE) -C ./lib/my/

libmy_fclean:
		$(MAKE) fclean -C ./lib/my/

libjson:
		$(MAKE) -C ./lib/markup/

libjson_fclean:
		$(MAKE) fclean -C ./lib/markup/

all:		$(NAME)

clean:
		$(MAKE) clean -C ./lib/my/
		$(MAKE) clean -C ./lib/markup/
		rm -f $(OBJ)

fclean:		libmy_fclean clean libjson_fclean clean
		rm -f $(NAME)

re: 		fclean all

.PHONY:		all clean fclean re
