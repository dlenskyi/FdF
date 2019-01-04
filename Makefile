# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/12 16:44:05 by dlenskyi          #+#    #+#              #
#    Updated: 2018/12/30 19:30:48 by dlenskyi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wall -Wextra -Werror -O3
CC = gcc

LIBX_KEY = -lmlx -lm -framework OpenGL -framework AppKit

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = ./libft/
LIBFT_HEAD = $(LIBFT_DIR)includes/
FDF_HEAD = fdf.h

INCLUDES = -I$(FDF_HEAD) -I$(LIBFT_HEAD)

SRC = set_color.c init_arr_of_struct.c kb_utils.c magic.c mouse_board_control.c parse_map.c \
projection.c main.c

OBJ = $(patsubst %.c, %.o, $(SRC))

RED = \x1B[31m
GREEN = \x1B[32m
OFF = \x1B[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(FLAGS) $(LIBX_KEY) $(INCLUDES) $(LIBFT) $(OBJ) -o $(NAME)
	@echo "$(GREEN)fdf completed!$(OFF)"

%.o: %.c $(FDF_HEAD)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

$(LIBFT):
	@echo "Compiling fdf project...\n"
	@echo "Compiling libft..."
	@$(MAKE) -sC $(LIBFT_DIR)
	@echo "$(GREEN)libft.a was created.$(OFF)"

clean:
	@$(MAKE) -sC $(LIBFT_DIR) clean
	@rm -f $(OBJ)
	@echo "$(RED)libft.a was removed$(OFF)"

fclean: clean
	@rm -f $(LIBFT)
	@rm -f $(NAME)
	@rm -f $(OBJ)
	@echo "$(RED)All objects were removed$(OFF)"

re: fclean all

