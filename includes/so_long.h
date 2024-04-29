/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:44:40 by aroualid          #+#    #+#             */
/*   Updated: 2024/04/29 11:21:27 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H

# define SO_LONG_H
# define SCALE 2
# define WIN_H 1080
# define WIN_W 1920

# include "../minilibx-linux/mlx_int.h"
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <limits.h>
# include <stdbool.h>
# include <stdint.h>


typedef struct s_game
{
	void				*mlx;
	void				*win;
	char				*map_path;
	char				**map;
	float				move_count;
	int					step_count;
	int					key_a;
	int					key_w;
	int					key_s;
	int					key_d;
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
	t_img				**sprites;
	t_img				*test;
	int					pp_x;
	int					pp_y;
	int					max_x;
	int					max_y;
}						t_game;

#endif
