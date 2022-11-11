# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mverbrug <mverbrug@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/11/08 14:19:06 by mverbrug      #+#    #+#                  #
#    Updated: 2022/11/11 11:23:03 by mverbrug      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf # NAME = name of executable
HEADER 	=	fdf.h
LIBFT 	=	libft/libft.a
PRINTF	=	printf/printf.a
MLX		=	MLX42/libmlx42.a
SANI	=	-g -fsanitize=address # $(SANI)
FLAGS 	=	-Wall -Wextra -Werror -g
FLAGS_M	=	-I include -lglfw3 -framework Cocoa \
				-framework OpenGL -framework IOKit
CC		= 	cc  # CC = compliler to be used
RM		=	rm -f # RM = the program to delete files
# SHELL 	:= /bin/bash # set bash path to include bash commands in recipe

# SRC = .c files
VPATH	=	./src

SRC		=	main.c			\
			parse_map.c		\
			read_map.c		\
			fill_data.c		\
			gnl.c
			

# OBJ = .o files
OBJ_DIR	=	./obj
OBJ	=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# Colors
P 		= 	\x1b[35m
B 		= 	\x1b[34m
Y 		= 	\x1b[33m
G 		= 	\x1b[32m
R 		= 	\x1b[31m
W 		= 	\x1b[0m

# "all" builds executable, should recompile only the updated source files
all:		$(NAME)

$(NAME):	$(OBJ) $(HEADER) $(LIBFT) $(PRINTF) $(MLX)
			@$(CC) $(OBJ) -I$(HEADER) $(LIBFT) $(PRINTF) $(MLX) $(FLAGS_M) -o$@
			@echo "$(Y)Just made... "
			@echo "\n$(Y)~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~$(W)\n"
			@echo "            $(Y)$@ $(G)$@ $(B)$@ $(P)$@ $(R)$@!"
			@echo "\n$(Y)~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~$(W)\n"

$(LIBFT):
			@echo "$(G)Created $(W)libft.a"
			@$(MAKE) -C libft

$(PRINTF):
			@echo "$(G)Created $(W)printf.a"
			@$(MAKE) -C printf

$(MLX):
			@echo "$(G)Created $(W)libmlx42.a"
			@$(MAKE) -C MLX42

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
			@$(MAKE) fclean -C MLX42
			@echo "$(P)$@ $(W)object files, obj directories, .a and executable"
			@$(RM) $(NAME)

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
			git commit -m "Input parsing stage, my favorite stage"
			git push origin master

# "Updatin' my way through life"
del:		fclean
			$(RM) *.DS_Store ./.DS_Store ./printf/.DS_Store
			$(RM) ./libft/.DS_Store ./libft/libft_src/.DS_Store
			$(RM) *.out ./libft/libft.a.5OzDFi
			rm -rf *.dSYM
