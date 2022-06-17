# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbeheyt <pbeheyt@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/31 15:08:45 by pbeheyt           #+#    #+#              #
#    Updated: 2022/06/17 04:24:22 by pbeheyt          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

SRC		= main.c check.c parsing.c operations.c operations2.c radix.c #short_resolve.c

DIR 	= ${addprefix srcs/,${SRC}}

HEAD	= -I libft -I include

CC 		= gcc

CFLAGS 	= -Wall -Wextra -Werror -g

OBJS 	= ${DIR:.c=.o}

LD_FLAG	= -L libft

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(LD_FLAG) $(OBJS) -lft


.c.o:
	${CC} ${CFLAGS} ${HEAD} -c $< -o ${<:.c=.o}

clean:
	make clean -C libft
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
