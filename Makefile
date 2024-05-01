# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/12 16:01:05 by aroualid          #+#    #+#              #
#    Updated: 2024/05/02 00:15:16 by aroualid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIGHT_RED=\033[1;31m
LIGHT_GREEN=\033[1;32m
LIGHT_YELLOW=\033[1;33m
LIGHT_BLUE=\033[1;34m
LIGHT_MAGENTA=\033[1;35m
LIGHT_CYAN=\033[1;36m
WHITE=\033[1;37m
LIGHT_GRAY=\033[0;37m
DARK_GRAY=\033[1;30m
LIGHT_PURPLE=\033[1;35m


CC = cc
CFLAGS=   -g3
LIBFT_PATH = libft
FT_PRINTF_PATH = ft_printf
MINILIBX_PATH = minilibx-linux
SRCS_PATH = src/
PARS_PATH = pars/
NAME = so_long

SRCS :=	$(addprefix $(SRCS_PATH), \
		main.c\
		sprite_fruit.c\
)

PARS := $(addprefix $(PARS_PATH), \
	check_finish.c \
	count_map.c \
	check_map.c \
	check_file_name.c \
	get_next_line.c \
)
OBJS = $(SRCS:%.c=%.o) $(PARS:%.c=%.o)


.PHONY: all clean fclean re libft re ft_printf

all:$(NAME) 
#	@echo "$(LIGHT_CYAN)Starting tasks..."
#	@i=0; while [ $$i -le 100 ]; do \
       # echo -n "Progress: [$$i%] "; \
       # printf "$(LIGHT_GREEN)=%.0s" $$(seq 1 $$((i / 2))); \
        #printf " "; \
       # printf "$(LIGHT_BLUE)%.0s" $$(seq $$((i / 2 + 1)) 50); \
      #  echo -n "\r"; \
     #   sleep 0.02; \
    #    i=$$((i+1)); \
    #done
	#@echo "$(LIGHT_MAGENTA)All tasks completed !                                                                "

$(NAME): $(OBJS) libft ft_printf minilibx
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -Llibft -lft -Lft_printf -lftprintf -Lminilibx-linux  -lmlx_Linux -lmlx -lX11 -lXext -lm

libft:
	$(MAKE) -C $(LIBFT_PATH)

ft_printf:
	$(MAKE) -C $(FT_PRINTF_PATH)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(MAKE) -C $(FT_PRINTF_PATH) fclean

re: fclean all

minilibx: 
	@$(MAKE) -C $(MINILIBX_PATH)
