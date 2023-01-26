# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 13:21:14 by mzarichn          #+#    #+#              #
#    Updated: 2022/11/10 15:44:02 by mzarichn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Werror -Wextra -Wall -I.
RM = rm -f

SRC = ft_atoi ft_bzero ft_calloc ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint ft_memcmp \
		ft_memcpy ft_memset ft_strlen ft_strlcpy ft_strlcat ft_strncmp ft_tolower ft_toupper \
		ft_substr ft_strdup ft_strnstr ft_strjoin ft_strchr ft_strtrim ft_strmapi ft_striteri \
		ft_split ft_putstr_fd ft_putnbr_fd ft_putendl_fd ft_putchar_fd ft_memmove ft_memchr ft_itoa \
		ft_strtrim ft_strrchr ft_strtrim ft_split
BONUS = ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back ft_lstdelone ft_lstclear ft_lstiter \
		ft_lstmap

all: $(NAME)

$(NAME): $(SRC:=.o)
		ar rc $(NAME) $(SRC:=.o) 
clean:
		$(RM)	$(SRC:=.o) $(BONUS:=.o)

fclean: clean
		$(RM)	$(NAME)

re: fclean $(NAME)

bonus: $(SRC:=.o)	$(BONUS:=.o)
		ar rc $(NAME) $(SRC:=.o)	$(BONUS:=.o)