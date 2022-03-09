# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emcariot <emcariot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/10 16:07:12 by emcariot          #+#    #+#              #
#    Updated: 2022/03/08 13:17:21 by emcariot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = 	main.c \
    	parsing/parsing.c \
        operations/reverse_rotate.c \
        operations/rotate.c \
        operations/swap.c \
        operations/push.c \
        free/free.c \
        errors/display_error.c \
        algos/sort_five_and_less.c \
        algos/radix_sort.c \
        toolbox/ft_atoi.c \
        toolbox/ft_split.c \
        toolbox/functions_for_list.c \
        toolbox/help.c \
        toolbox/index.c \

OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all: ${NAME} 

clean: 
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

