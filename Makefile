##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Standard Makefile configuration
##

SRC	=	$(wildcard src/*.c) $(wildcard ./src/*/*.c) $(wildcard ./lib/*/*.c) $(wildcard src/*/*/*.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	42sh

GCC	=	gcc

ifneq		(,$(wildcard ./debug))
CFLAGS	=	-ggdb3 -pedantic -Wduplicated-cond -Wall -Wextra\
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

LDFLAGS	+=	-L./lib/my/ -lmy -lm

.SILENT:

$(NAME):	libmy $(OBJ)
		$(GCC) -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS)

libmy:
		$(MAKE) -C ./lib/my/

libmy_fclean:
		$(MAKE) fclean -C ./lib/my/

all:		$(NAME)

clean:
		$(MAKE) clean -C ./lib/my/
		rm -f $(OBJ)

fclean:		libmy_fclean clean
		rm -f $(NAME)

re: 		fclean all

.PHONY:		all clean fclean re
