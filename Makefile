# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/27 14:33:38 by vpluchar          #+#    #+#              #
#    Updated: 2017/10/27 17:05:45 by vpluchar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

INC = -I./libft/includes/ -I./inc/

LIB = libft/

DOBJ	=	obj
SDIR = src

SRC = src/fractol.c \
	  src/fractale.c \
	  src/fractale_b1.c \
	  src/fractale_b2.c \
	  src/key.c \
	  src/menu.c

GCC = gcc -Wall -Wextra -Werror

FRAM = -lmlx -framework OpenGL -framework Appkit

OBJ 	=	$(patsubst %.c, $(DOBJ)/%.o, $(SRC))
ODIR	=	$(addprefix $(DOBJ)/, $(SDIR))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@$(GCC) $(FRAM) -o $(NAME) $(INC) $(OBJ) -L$(LIB) -lft
	@echo "\033[0;33;32mmake Fractol"

$(DOBJ)/%.o:%.c
	@mkdir -p $(ODIR) 
	@$(GCC) $(INC) -c $< -o $@

clean:
	@make clean -C $(LIB)
	@rm -rf $(DOBJ)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIB)

re: fclean all
