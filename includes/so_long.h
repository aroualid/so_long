/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:44:40 by aroualid          #+#    #+#             */
/*   Updated: 2024/05/22 14:03:17 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H
# define WIN_H 1080
# define WIN_W 1920
# define SCALE 3

# include "../minilibx-linux/mlx_int.h"
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <limits.h>
# include <stdbool.h>
# include <stdint.h>

typedef struct s_xorshift32_state
{
	uint32_t	a;
}	t_xorshift32_state;

typedef struct s_exit
{
	int	x;
	int	y;
}	t_exit;

typedef struct s_wall
{
	int	x;
	int	y;
}	t_wall;

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


typedef struct s_ennemy
{
	int		x;
	int		y;
	t_img	**player_sprites;
	int		player_index;
}	t_ennemy;

typedef struct s_game
{
	int					x;
	int					y;
	int					col_x;
	int					col_y;
	int					ex_x;
	int					ex_y;
	int					col_numbers;
	void				*mlx;
	void				*win;
	char				*map_path;
	char				**map;
	char				**map_ok;
	int					scale_calc;
	t_img				*tree;
	int					sol_index;
	t_img				**sol;
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
	int					col_num;
	int					frame_count;
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
	t_ennemy			ennemy;
	t_xorshift32_state	rand;
	t_exit				exit;
	t_wall				wall;
	int					scale;
	int					sol_frame;
	int					bonus;
	t_img				**font_1;
	int					font_index;
	int					walk;
	t_img				**num;
	int					num_index;
	int					num_x;
	t_img				**w;
	t_img				**a;
	t_img				**s;
	t_img				**d;
	t_img				touch_index;
	int					w_ind;
	int					a_ind;
	int					s_ind;
	int					d_ind;
}						t_game;

t_img		*load_sprite(void *img, char *filename);
t_img		**load_apple(t_game *game);
t_img		**load_lemon(t_game *game);
t_img		**load_pear(t_game *game);
t_img		**load_strawberry(t_game *game);
t_img		**load_watermelon(t_game *game);
void		update_player(t_game *game);
void		draw_sprite(t_game *game, t_img *img, int x, int y);
int			close_game(t_game *game);
int			key_pressed(int keycode, t_game *game);
int			key_released(int keycode, t_game *game);
void		detect_key(t_game *game);
void		clear_sprites(t_game *game);
void		draw_exit(t_game *game);
uint32_t	xorshift32(t_xorshift32_state *state);
void		draw_all(t_game *game);
int			update(t_game *game);
int			init_mlx_settings(t_game *game, int x, int y);
void		load_duck(t_game *game);
void		load_duck_reverse(t_game *game);
void		load_duck_wait(t_game *game);
void		load_duck_wait_reverse(t_game *game);
void		load_mechant(t_game *game);
void		load_fruit(t_game *game);
void		generate_random_fruit(t_game *game, int index);
void		load_exit(t_game *game);
void		player_key_w(t_game *game);
void		player_key_s(t_game *game);
void		player_key_a(t_game *game);
void		player_key_d(t_game *game);
void		walk_animation(t_game *game);
void		draw_enemy(t_game *game);
void		load_game(t_game *game);
void		random_p(t_game *game);
bool		wall_col(t_game *game, int x2, int y2);
void		load_font_1(t_game *game);
void		duck_space(t_game *game);
void		free_map(t_game *game);
void		load_num(t_game *game);
void		ft_put_nbr_to_win(t_game *game, int walk, int x);
void		draw_text(t_game *game, t_img *img, int x, int y);
void		free_all(t_game *game);
void		free_sprite(t_img **ptr, int index, t_game *game);
void		free_fruit(t_game *game);
void		load_touch(t_game *game);
void		draw_touch(t_game *game, t_img *img, int x, int y);
#endif
