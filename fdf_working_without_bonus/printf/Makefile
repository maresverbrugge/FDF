# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mverbrug <mverbrug@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/04/06 12:23:43 by mverbrug      #+#    #+#                  #
#    Updated: 2022/11/09 12:55:55 by mverbrug      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		=	printf.a
HEADER_FILE	=	printf.h
FLAGS		=	-Wall -Wextra -Werror -g
VPATH		=	./printf_src
SRCS		=	ft_printf.c			\
				print_s_c.c			\
				print_d_i_u.c		\
				print_x_X_p.c
OBJ_DIR		=	./printf_obj
OBJS		=	$(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
RM			=	rm -f
LIBC		=	ar -rcs
CC			=	gcc

all: 		$(NAME)

$(NAME):	$(OBJS)
			@$(LIBC) $(NAME) $(OBJS)

$(OBJ_DIR)/%.o:		%.c
					@mkdir -p $(OBJ_DIR)
					@$(CC) -c $(FLAGS) $< -o $@

clean:
			@${RM} -r $(OBJ_DIR)

fclean:		clean
			@${RM} $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
