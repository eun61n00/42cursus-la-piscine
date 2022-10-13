# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/27 12:07:45 by eukwon            #+#    #+#              #
#    Updated: 2022/01/27 15:42:07 by eukwon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER_DIR = ./da_oh.h
SRCS= ./main.c ./util.c
NAME = do-op
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) :
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) -I $(HEADER_DIR)

clean :
	rm -rf $(OBJS)	

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY:
	all clean fclean re
