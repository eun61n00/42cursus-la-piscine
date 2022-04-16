# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/23 09:44:22 by eukwon            #+#    #+#              #
#    Updated: 2022/01/23 10:04:24 by eukwon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!bin/bash

gcc -c ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c

ar crs libft.a ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o
