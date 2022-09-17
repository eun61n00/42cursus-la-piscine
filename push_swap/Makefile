# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eukwon <eukwon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/14 10:20:40 by eukwon            #+#    #+#              #
#    Updated: 2022/09/17 09:34:03 by eukwon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAG = -Wall -Wextra -Werror

AR = ar
ARFLAG = -crs

RM = rm
RMFLAG = -rf

INCLUDES_DIR = ./includes
SRCS_DIR = ./srcs
OBJS_DIR = ./objs

# libft
LIBFT = libft.a
LIBFT_DIR = ./lib/libft
LIBFT_FILE = $(LIBFT_DIR)/$(LIBFT)
LIBFT_FLAGS = -L $(LIBFT_DIR) -lft
LIBFT_INC_DIR = $(LIBFT_DIR)/includes

# ft_printf
FT_PRINTF = libftprintf.a
FT_PRINTF_DIR = ./lib/ft_printf
FT_PRINTF_FILE = $(FT_PRINTF_DIR)/$(FT_PRINTF)
FT_PRINTF_FLAGS = -L $(FT_PRINTF_DIR) -lft
FT_PRINTF_INC_DIR = $(FT_PRINTF_DIR)/includes

SRCS = $(addprefix $(SRCS_DIR)/, \
	main.c\
	check_error.c\
	parsing.c\
	swap.c\
	push.c\
	rotate.c\
	stack_operations.c\
	sort.c\
	quick_sort.c\
)

OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

# Color
NO_COLOR = \e[0m

LIGHT_GREEN = \e[1;32;189;147;249m
GREEN = \e[0;32;189;147;249m
LIGHT_GRAY = \e[1;32;255;121;198

LF = \e[1K\r$(NO_COLOR)
CRLF = \n$(LF)

all : $(NAME)

$(NAME) : $(OBJS) libft ft_printf
	@printf "$(LF)🚀 $(LIGHT_GREEN)Successfully Created $(GREEN)$(NAME)'s Object files!"
	@printf "$(CRLF)📚 $(LIGHT_GREEN)Archiving! $(GREEN)$@${CRLF}"
	$(CC) $(CFLAG) $(OBJS) $(LIBFT_DIR)/$(LIBFT) $(FT_PRINTF_DIR)/$(FT_PRINTF) -I $(INCLUDES_DIR) $(LIBFT_FLAGS) $(FT_PRINTF_FLAGS) -o $(NAME) -g
	@printf "$(LF)🎉 $(LIGHT_GREEN)Successfully Archived $(GREEN)$@ $(LIGHT_GREEN)!${CRLF}"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c libft ft_printf
	@mkdir $(OBJS_DIR) 2> /dev/null || true
	$(CC) $(CFLAG) -c $< -o $@ -I $(INCLUDES_DIR) -I $(LIBFT_INC_DIR) -I $(FT_PRINTF_INC_DIR) -g
	@printf "$(LF)🚧 $(LIGHT_GREEN)Create $(GREEN)$@ $(LIGHT_GREEN)from $(GREEN)$<${CRLF}"

libft :
	$(MAKE) -C ./lib/libft all

ft_printf:
	$(MAKE) -C ./lib/ft_printf all

clean :
	@$(MAKE) -C ./lib/libft clean
	@$(MAKE) -C ./lib/ft_printf clean
	@${RM} $(RMFLAG) $(OBJS)
	@printf "$(LF)🧹 $(LIGHT_GREEN)Cleaning $(GREEN)$(NAME)'s Object files...${CRLF}"

fclean : clean
	@${RM} $(RMFLAG) $(NAME)
	@printf "$(LF)🧹 $(LIGHT_GREEN)Cleaning $(GREEN)$(NAME)${CRLF}"

re : fclean all

.PHONY : all libft ft_printf clean fclean re