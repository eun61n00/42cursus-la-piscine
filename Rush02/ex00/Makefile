# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junsoh <junsoh@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/23 20:30:35 by junsoh            #+#    #+#              #
#    Updated: 2022/01/23 20:30:52 by junsoh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Iincludes
SRC_DIR=./srcs
INCLUDE_DIR=./includes
HEADERS=$(wildcard $(INCLUDE_DIR)/*.h)
SRCS=$(wildcard $(SRC_DIR)/*.c)
OBJS=$(SRCS:.c=.o)

NAME = rush-02
all : $(NAME)
$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
dep :
	gccmakedep $(INCLUDE_DIR) $(SRCS)
clean:
	find . -type f \( -name "*.d" -o -name "*.o" \) -delete
fclean:	clean
	find . -type f -name $(NAME) -delete
re : fclean all