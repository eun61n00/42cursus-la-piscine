# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eukwon <eukwon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/14 10:20:40 by eukwon            #+#    #+#              #
#    Updated: 2022/08/27 16:25:42 by eukwon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
# CFLAG = -Wall -Wextra -Werror

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
	)
OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

# Color
CL_BOLD =\e[1m
CL_DIM =\e[2m
CL_UDLINE = \e[4m

NO_COLOR = \e[0m

BG_TEXT = \e[48;2;45;55;72m
BG_BLACK = \e[48;2;30;31;33m

FG_WHITE = $(NO_COLOR)\e[0;37m
FG_TEXT = $(NO_COLOR)\e[38;2;189;147;249m
FG_TEXT_PRIMARY = $(NO_COLOR)$(CL_BOLD)\e[38;2;255;121;198m

LF = \e[1K\r$(NO_COLOR)
CRLF = \n$(LF)

all : $(NAME)

$(NAME) : $(OBJS) libft ft_printf
	@printf "$(LF)🚀 $(FG_TEXT)Successfully Created $(FG_TEXT_PRIMARY)$(NAME)'s Object files $(FG_TEXT)!"
	@printf "$(CRLF)📚 $(FG_TEXT)Archiving! $(FG_TEXT_PRIMARY)$@"
	$(CC) $(CFLAG) $(OBJS) $(LIBFT_DIR)/$(LIBFT) $(FT_PRINTF_DIR)/$(FT_PRINTF) -I $(INCLUDES_DIR) $(LIBFT_FLAGS) $(FT_PRINTF_FLAGS) -o $(NAME) -g
	@printf "$(LF)🎉 $(FG_TEXT)Successfully Archived $(FG_TEXT_PRIMARY)$@ $(FG_TEXT)!\n"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c libft ft_printf
	@mkdir $(OBJS_DIR) 2> /dev/null || true
	$(CC) $(CFLAG) -c $< -o $@ -I $(INCLUDES_DIR) -I $(LIBFT_INC_DIR) -I $(FT_PRINTF_INC_DIR) -g
	@printf "$(LF)🚧 $(FG_TEXT)Create $(FG_TEXT_PRIMARY)$@ $(FG_TEXT)from $(FGma_TEXT_PRIMARY)$<"

libft :
	$(MAKE) -C ./lib/libft all

ft_printf:
	$(MAKE) -C ./lib/ft_printf all

clean :
	@$(MAKE) -C ./lib/libft clean
	@$(MAKE) -C ./lib/ft_printf clean
	@$(RM) $(RMFLAG) $(OBJS)
	@printf "$(LF)🧹 $(FG_TEXT)Cleaning $(FG_TEXT_PRIMARY)$(NAME)'s Object files...\n"

fclean : clean
	@$(RM) $(RMFLAG) $(NAME)
	@printf "$(LF)🧹 $(FG_TEXT)Cleaning $(FG_TEXT_PRIMARY)$(NAME)\n"

re : fclean all

.PHONY : all libft ft_printf clean fclean re