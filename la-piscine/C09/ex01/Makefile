# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 13:26:02 by eukwon            #+#    #+#              #
#    Updated: 2022/01/28 07:53:28 by eukwon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
TARGET = libft.a
SRCS_DIR = ./srcs
INCLUDE_DIR = ./includes
SRCS = ./srcs/ft_putchar.c ./srcs/ft_swap.c ./srcs/ft_putstr.c ./srcs/ft_strlen.c ./srcs/ft_strcmp.c
OBJS = ${SRCS:.c=.o}
INCLUDES = $(INCLUDE_DIR)

all : $(TARGET)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@ -I${INCLUDES}

clean :
	rm -rf ${OBJS}

fclean: clean
	rm -f $(TARGET)

re: fclean all

$(TARGET) : $(OBJS)
	ar crvs $(TARGET) $(OBJS)

.PHONY:
	all clean fclean re .c.o

