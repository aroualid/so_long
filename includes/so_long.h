/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:44:40 by aroualid          #+#    #+#             */
/*   Updated: 2024/05/03 18:12:36 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H

# define SO_LONG_H
# define SCALE 2
# define WIN_H 1080
# define WIN_W 1920 - 64

# include "../minilibx-linux/mlx_int.h"
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <limits.h>
# include <stdbool.h>
# include <stdint.h>


typedef struct s_xorshift32_state
{
    uint32_t    a;
}        t_xorshift32_state;


typedef struct s_collectible
{
	int		x;
	int		y;
	t_img	**fruit_sprites;
	int		sprite_index;
}	t_collectible;

typedef struct s_player
{
	int		x;
	int		y;
	t_img	**player_sprites;
	int		player_index;
}	t_player;


typedef struct s_game
{
	void				*mlx;
	void				*win;
	char				*map_path;
	char				**map;
	char				**map_ok;
	float				move_count;
	int					step_count;
	int					key_a;
	int					key_w;
	int					key_s;
	int					key_d;
	int					last_key;
	int					key_space;
	int					key_esc;
	int					map_width;
	int					map_height;
	int					collectibles_numbers;
	int					bg1_scroll;
	int					bg2_scroll;
	int					water_scroll;
	int					fg_scroll;
	int					accessible_collectibles;
	int					accessible_door;
	int					max_jump;
	int					frame_count;
	bool				is_trail_drawn;
	bool				spawn_enemy;
	t_img				*screen;
	t_img				**sprites_duck_wait;
	int					sprite_duck_wait;
	t_img				**sprites_duck_wait_reverse;
	int					sprite_duck_wait_reverse;

	t_img				**sprites;

	t_img				**correct_sprites;
	t_img				**reverse_sprites;
	t_img				**sprites_m;
	int					sprite_reverse;
	int					sprite_index;
	int					sprite_mechant;
	int					pp_x;
	int					pp_y;
	int					max_x;
	int					max_y;
	unsigned long		nb_frames;
	int					fruit_index;
	t_img				**sprites_apple;
	t_img				**sprites_lemon;
	t_img				**sprites_pear;
	t_img				**sprites_strawberry;
	t_img				**sprites_watermelon;
	t_img				***load_fruit;
	t_collectible		*collectibles;
	t_player			player;
	t_xorshift32_state	rand;
	int					scale;
}						t_game;

t_img	*load_sprite(void *img, char *filename);
t_img	**load_apple(t_game *game);
t_img	**load_lemon(t_game *game);
t_img	**load_pear(t_game *game);
t_img	**load_strawberry(t_game *game);
t_img	**load_watermelon(t_game *game);
int		update_player(t_game *game);


#endif
