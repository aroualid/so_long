# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/12 16:01:05 by aroualid          #+#    #+#              #
#    Updated: 2024/04/12 17:36:44 by aroualid         ###   ########.fr        #
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
CFLAGS=  -Wall -Wextra -Werror  -g3
LIBFT_PATH = libft/
MINILIBX_PATH = minilibx-linux
SRCS_PATH = src/
NAME = so_long

SRCS :=	$(addprefix $(SRCS_PATH), \
		main.c\
)
OBJS = $(SRCS:%.c=%.o)

all: $(NAME) 
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

$(NAME): $(OBJS) minilibx libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)  -L$(LIBFT_PATH) -Lminilibx-linux -lmlx_Linux -lmlx -lX11 -lXext -lm

libft:
	$(MAKE) -C $(LIBFT_PATH)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

minilibx: 
	@$(MAKE) -C $(MINILIBX_PATH)
