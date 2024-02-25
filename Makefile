# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cel-bahr <cel-bahr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/03 22:40:28 by cel-bahr          #+#    #+#              #
#    Updated: 2024/02/25 01:41:38 by cel-bahr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
ARC = ar rc
RM = rm -f
SRCS = ft_printf.c i_print_str.c i_print_num.c i_print_hex.c
OBJS = $(SRCS:%.c=%.o)

all : $(NAME)

%.o : %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(ARC) $(NAME) $(OBJS)
	
clean :
	$(RM) $(OBJS)

fclean : clean 
	$(RM) $(NAME)

re : fclean all

.PHONY: clean
