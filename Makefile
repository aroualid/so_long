# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/12 16:01:05 by aroualid          #+#    #+#              #
#    Updated: 2024/05/22 11:59:49 by aroualid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -O3 -fno-builtin
LIBFT_PATH = libft
FT_PRINTF_PATH = ft_printf
MINILIBX_PATH = minilibx-linux
SRCS_PATH = src/
PARS_PATH = pars/
NAME = so_long
NAME_BNS = so_long_bonus

SRCS :=	$(addprefix $(SRCS_PATH), \
	init_game.c \
	key.c \
	load_duck.c \
	load_sprites.c \
	main.c \
	sprite_fruit.c \
	update.c \
	update_duck.c \
	duck_move.c \
	draw_sprite.c \
	load_font.c \
	free.c \
	utils.c\
	load_touch.c\
)

PARS := $(addprefix $(PARS_PATH), \
	check_finish.c \
	count_map.c \
	check_map.c \
	check_file_name.c \
	get_next_line.c \
)

SRCS_BNS := $(addprefix $(SRCS_PATH), \
	init_game.c\
	utils.c \
	key.c \
	load_duck.c \
	load_sprites.c \
	sprite_fruit.c \
	update.c \
	update_duck.c \
	duck_move.c \
	draw_sprite.c \
	bonus.c \
	load_font.c \
	load_touch.c\
	free.c \
)

PARS_BNS := $(addprefix $(PARS_PATH), \
	check_finish.c \
	pars_bonus.c \
	count_map.c \
	check_map.c \
	check_file_name.c \
	get_next_line.c \
)


OBJS = $(SRCS:%.c=%.o) $(PARS:%.c=%.o)

OBJS_BNS = $(SRCS_BNS:%.c=%.o) $(PARS_BNS:%.c=%.o)

.PHONY: all clean fclean re libft re ft_printf

all: $(NAME) 

$(NAME): $(OBJS) libft ft_printf minilibx
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -Llibft -lft -Lft_printf -lftprintf -Lminilibx-linux  -lmlx_Linux -lmlx -lX11 -lXext -lm

bonus : $(OBJS_BNS) libft ft_printf minilibx
	$(CC) $(CFLAGS) -o $(NAME_BNS) $(OBJS_BNS) -Llibft -lft -Lft_printf -lftprintf -Lminilibx-linux  -lmlx_Linux -lmlx -lX11 -lXext -lm

libft:
	@$(MAKE) -C $(LIBFT_PATH)

ft_printf:
	@$(MAKE) -C $(FT_PRINTF_PATH)

minilibx: 
	@$(MAKE) -C $(MINILIBX_PATH)

clean:
	@$(RM) $(OBJS)
	@cd $(LIBFT_PATH) && make clean
	@cd $(FT_PRINTF_PATH) && make clean
	@cd $(MINILIBX_PATH) && make clean

fclean: clean
	@$(RM) $(NAME)
	@cd $(LIBFT_PATH) && make fclean
	@cd $(FT_PRINTF_PATH) && make fclean

re: fclean all


