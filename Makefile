# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 12:55:24 by anastacia         #+#    #+#              #
#    Updated: 2022/10/13 15:35:39 by anastacia        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

$(VERBOSE).SILENT:

NAME = philo

SRC = main threads parse utils ft_atoi init routine\

CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra
INC = -I. -fsanitize=thread -pthread

all: $(NAME)

$(NAME): $(SRC:=.o)
	$(CC) $(CFLAGS) $(INC) $(SRC:=.o) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	$(RM) $(NAME)

fclean: clean
	$(RM) $(SRC:=.o)

re: fclean all

.PHONY: all clean fclean re