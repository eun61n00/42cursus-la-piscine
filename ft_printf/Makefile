# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/17 15:32:00 by eukwon            #+#    #+#              #
#    Updated: 2022/06/18 16:36:49 by eukwon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = AR
ARFLAGS = crs
NAME = libftprintf.a
INCLUDES = ./ft_printf.h
SRCS = \
./ft_atoi.c \
./ft_isdigit.c \
./ft_itoa.c \
./ft_printf.c \
./ft_putchar.c \
./ft_putnbr_base.c \
./ft_putstr.c \
./ft_strdup.c \
./ft_strlen.c
OBJS = $(SRCS:.c=.o)

%.o : %.c
	${CC} ${CFLAGS} -c $^ -o $@ -I ${INCLUDES}

all : $(NAME)

$(NAME) : $(OBJS)
	${AR} ${ARFLAGS} $(NAME) $(OBJS)

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re