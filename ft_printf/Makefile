# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eukwon <eukwon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/17 15:32:00 by eukwon            #+#    #+#              #
#    Updated: 2022/10/02 13:38:32 by eukwon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = AR
ARFLAG = -crs

RM = rm
RMFLAG = -rf

INCLUDES_DIR = ./includes

SRCS_DIR = ./srcs
SRCS_NAME = \
ft_isdigit.c \
ft_itoa.c \
ft_printf.c \
ft_putchar_pf.c \
ft_putnbr_base.c \
ft_putstr_pf.c \
ft_strdup.c \
ft_strlen.c
SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_NAME))

OBJS_DIR = ./objs
OBJS_NAME = $(SRCS_NAME:.c=.o)
OBJS = $(addprefix $(OBJS_DIR)/, $(OBJS_NAME))

all : $(NAME)

$(NAME) : $(OBJS)
	${AR} ${ARFLAGS} $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir $(OBJS_DIR) 2> /dev/null || true
	$(CC) $(CFLAGS) -c $^ -o $@ -I $(INCLUDES_DIR)

clean :
	$(RM) $(RMFLAG) $(OBJS_DIR) $(NAME)

fclean : clean
	$(RM) $(RMFLAG) $(NAME)

re : fclean all

.PHONY: all clean fclean re