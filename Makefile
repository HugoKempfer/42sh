##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Standard Makefile configuration
##

SRC	=	src/process_manager/manage_processes.c \
		src/init/init_var_s.c \
		src/init/env.c 					\
		src/init/shell_info.c 		\
		src/init/init_alias.c 		\
		src/init/shell_path.c 		\
		src/post_processing/is_specific_command.c 		\
		src/post_processing/process/process_globings.c 		\
		src/post_processing/process/process_alias.c 		\
		src/post_processing/process/process_coat.c 		\
		src/post_processing/is_specific_surrondings.c 		\
		src/post_processing/tree_post_processing.c 		\
		src/post_processing/get_process_function.c 		\
		src/history/history.c 		\
		src/command_interpreter/buffer_to_stdin.c 		\
		src/command_interpreter/process_scheduler.c 		\
		src/command_interpreter/file_to_stdin.c 		\
		src/command_interpreter/pipe.c 		\
		src/command_interpreter/binary.c 		\
		src/command_interpreter/file_redirect.c 		\
		src/command_lexer/tokenizer.c 		\
		src/command_lexer/destroy.c 		\
		src/command_lexer/str_utils.c 		\
		src/command_lexer/string_cutter_annex.c 		\
		src/command_lexer/string_cutter.c 		\
		src/var/var_management.c 		\
		src/var/var_helpers.c 		\
		src/main.c 		\
		src/syntax_check/check_syntax_error.c 		\
		src/built_in/echo/echo.c 		\
		src/built_in/cd/cd_management.c 		\
		src/built_in/env/env_management.c 		\
		src/command_parser/tree_builder.c 		\
		src/command_parser/branch_builder.c 		\
		src/command_parser/branch_builder_annex.c 		\
		src/shell_scheduler/shell_scheduler.c 		\
		src/prompt/prompt.c 		\
		src/tree_manager/create.c 		\
		src/binary/exec_binary.c 		\
		src/binary/exec_errors.c 		\
		src/alias/add_alias.c


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

LDFLAGS	+=	-L./lib/my/ -lmy -lm -Lbuild -lmarkup_parser

$(NAME):	libmy libjson $(OBJ)
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
