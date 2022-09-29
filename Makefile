# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 14:07:06 by anastacia         #+#    #+#              #
#    Updated: 2022/09/29 16:46:41 by anastacia        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

$(VERBOSE).SILENT:

NAME = philo

SRC = main ft_atoi parse\

CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -I. -fsanitize=address -lpthread

all: $(NAME)

$(NAME): $(SRC:=.o)
	$(CC) $(CFLAGS) $(SRC:=.o) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	$(RM) $(NAME)

fclean: clean
	$(RM) $(SRC:=.o)

re: fclean all

.PHONY: all clean fclean re