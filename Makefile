# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/24 16:54:38 by mzarichn          #+#    #+#              #
#    Updated: 2023/01/30 17:16:35 by mzarichn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#----- Program name:
NAME	= fractol

#---- Compilation:
CC = gcc
CFLAGS = -Wall -Werror -Wextra -Imlx -g
MILIB  = -I /usr/X11/include -g -L /usr/X11/lib -l minilibx-linux -framework OpenGL -framework AppKit

#----- Printf:
FT_PRINTF_PATH	= ./ft_printf 
FT_PRINTF_NAME	= ./ft_printf/libftprintf.a

#----- MiniLibx:
MLX_LIB_DIR = minilibx-linux/
MLX_INCLUDE = -I minilibx-linux/
LMLX_FLAGS = -L$(MLX_LIB_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -fPIC

#----- Colors:
RED = \033[0;91m
DEFAULT = \033[0;39m
GREEN = \033[0;92m

#----- Files:
SRC	= ./src/fractol.c\
	./src/utils.c\
	./src/key_handler.c\
	./src/start_utils.c\
	./src/end_utils.c\
	./src/help.c\



OBJ	= $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
		@echo "$(RED)\nCompiling Printf..\n$(DEFAULT)"
		make -C $(FT_PRINTF_PATH)
		@echo "$(GREEN)\nDone Compiling...\n$(DEFAULT)"
		@echo "$(RED)\nCompiling MLX..\n$(DEFAULT)"
		make -C minilibx-linux/
		$(CC) $(CFLAGS) $(OBJ) $(FT_PRINTF) $(LMLX_FLAGS) $(MLX_INCLUDE) -o $(NAME)
		@echo "$(GREEN)\nDone Compiling...\n$(DEFAULT)"


clean:
		@echo "$(RED)\nCleaning...\n$(DEFAULT)"
		$(RM) $(OBJ)
		make clean -C $(FT_PRINTF_PATH)
		@echo "$(GREEN)\nDone Cleaning...\n$(DEFAULT)"

fclean:			clean
				$(RM) $(NAME)
				make fclean -C $(FT_PRINTF_PATH)
				@echo "$(GREEN)\nDone Function Cleaning...\n$(DEFAULT)"
		
re:				fclean $(NAME)
