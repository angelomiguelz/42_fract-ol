# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/24 16:54:38 by mzarichn          #+#    #+#              #
#    Updated: 2023/01/25 18:15:07 by mzarichn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#----- Program name:
NAME	= fractol

#---- Compilation:
CC	= cc
FLAGS	= -Wall -Wextra -Werror

#----- Printf:
FT_PRINTF_PATH	= ./ft_printf 
FT_PRINTF_NAME	= ./ft_printf/libftprintf.a

#----- MiniLibx:
MLX_PATH	= ./minilibx_mms_20191025_beta

#----- Files:
SRC	= ./src/fractol.c\

OBJ	= $(SRC:.c=.o)

all: $(FT_PRINTF) $(NAME)

$(FT_PRINTF):
		@make -C $(PRINTF_PATH)
		@echo "Compiling Printf..."
# $(MLX):
# 		@echo "Compiling MiniLibX..."
# 		@make -C $(MLX_PATH)

$(NAME): $(OBJ)
		@echo "Compiling Printf..."
		@make -C $(PRINTF_PATH)
		@echo "Compiling Fractol..."
		@$(CC) $(CFlags) $(OBJ) $(MLX) $(FT_PRINTF_NAME) -o $(NAME)
		@echo "Fractol ready."
		
