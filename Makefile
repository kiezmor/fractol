# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/27 14:33:38 by vpluchar          #+#    #+#              #
#    Updated: 2017/10/27 14:33:38 by vpluchar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

HEAD = fractol.h

LIB = libft/

SRC = src/fractol.c \
	  src/fractale.c \
	  src/fractale_b1.c \
	  src/fractale_b2.c \
	  src/key.c \
	  src/menu.c

GCC = gcc -Wall -Wextra -Werror -lmlx -framework OpenGL -framework Appkit

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@$(GCC) -o $(NAME) $(OBJ) -L$(LIB) -lft
	@echo "\033[0;33;32mmake Fractol"

%.o: %.c $(HEAD)
	@$(GCC)  -c $<

clean:
	@make clean -C $(LIB)
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIB)

re: fclean all