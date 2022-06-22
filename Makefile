# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akadi <akadi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 12:49:08 by akadi             #+#    #+#              #
#    Updated: 2022/06/22 17:36:52 by akadi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= cc
NAME=philo
CFLAGS= -Wall -Wextra -Werror
SRCS=philo.c\
	check_error.c\
	ft_strlen.c\
	initial.c\
	eating.c\

OBJS=$(SRCS:.c=.o)
INCL= philo.h

all:$(NAME)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -g

%.o: %.c $(INCL)
	$(CC) $(CFLAGS) -c $< -g

clean:
	rm -rf *.o

fclean:clean
	rm -rf philo

re : fclean all

.PHONY: all bonus clean fclean re