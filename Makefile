# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mverbrug <mverbrug@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/11/08 14:19:06 by mverbrug      #+#    #+#                  #
#    Updated: 2022/11/08 15:42:55 by mverbrug      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME_M	=	fdf # NAME = name of executable
HEADER 	=	fdf.h
LIBFT 	=	libft/libft.a
PRINTF	=	printf/printf.a
FLAGS 	=	-Wall -Wextra -Werror -g
CC		= 	cc  # CC = compliler to be used
RM		=	rm -f # RM = the program to delete files
# SHELL 	:= /bin/bash # set bash path to include bash commands in recipe

# SRC = .c files
VPATH	=	./src

SRC_M	=	main.c

SRC		=	get_next_line.c

# OBJ = .o files
OBJ_DIR	=	./obj
OBJ_M	=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o) $(SRC_M:.c=.o))

# Colors
P 		= 	\x1b[35m
B 		= 	\x1b[34m
Y 		= 	\x1b[33m
G 		= 	\x1b[32m
R 		= 	\x1b[31m
W 		= 	\x1b[0m

# "all" builds executable, should recompile only the updated source files
all:		$(NAME)

$(NAME):	$(OBJ) $(LIBFT) $(PRINTF) $(HEADER)
			@$(CC) $(OBJ) -I $(HEADER) $(LIBFT) $(PRINTF) -o $@
			@echo "$(Y)Just made... "
			@echo "\n$(Y)~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~$(W)\n"
			@echo "            $(Y)$@ $(G)$@ $(B)$@ $(P)$@ $(R)$@!"
			@echo "\n$(Y)~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~$(W)\n"

$(LIBFT):
			@echo "$(G)Created $(W)libft"
			@$(MAKE) -C libft

$(PRINTF):
			@echo "$(G)Created $(W)printf"
			@$(MAKE) -C printf

$(OBJ_DIR)/%.o:		%.c
			@mkdir -p $(OBJ_DIR)
			@echo "$(B)Compiling$(W) $< to $@"
			@$(CC) -c $(FLAGS) $< -o $@

# clean deletes temporary/object files
clean:
			@echo "\n$(R)$@ $(W)object files and obj directory"
			@${RM} -r $(OBJ_DIR)

# fclean deletes temporary/object files and executable
fclean: 	clean
			@$(MAKE) fclean -C libft
			@$(MAKE) fclean -C printf
			@echo "$(P)$@ $(W)object files, obj directories, .a and executable"
			@$(RM) $(NAME_M)

# re forces recompilation of all source files
re: 		fclean all
			@echo "\n\n$(W)	   	      Restarted\n"
			@echo "	      	        $(Y)F$(G)D$(B)F$(P)!$(R)!\n"
			@echo "\n\n$(Y)~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~$(W)\n"

# compile with fsanitize to check for leaks
fsani:


.PHONY:		all bonus clean fclean re

norm:		del
			norminette

git: 		del
			git add *
			git commit -m "Start of the project"
			git push origin master

# "Updatin' my way through life"
del:		fclean
			$(RM) *.DS_Store ./.DS_Store
			$(RM) ./libft/.DS_Store ./libft/libft_src/.DS_Store
			$(RM) *.out ./libft/libft.a.5OzDFi
			rm -rf *.dSYM