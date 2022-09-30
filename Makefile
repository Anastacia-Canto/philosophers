# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 14:07:06 by anastacia         #+#    #+#              #
#    Updated: 2022/09/30 17:23:47 by anastacia        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

$(VERBOSE).SILENT:

NAME = philo

SRC = main utils/ft_atoi utils/utils parse routine\

CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -I. -lpthread -fsanitize=thread -pthread

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