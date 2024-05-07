/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:53:03 by aroualid          #+#    #+#             */
/*   Updated: 2024/05/07 15:56:55 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	exit_animation(t_game *game, int y, int x)
{
	int	x_scale;
	int	y_scale;

	x_scale = x * 32 * game->scale;
	y_scale = y * 32 * game->scale;
	draw_sprite(game, game->sol[game->sol_index], x_scale, y_scale);
	if (game->sol_frame % 32 / game->scale == 0 && game->sol_index < 3)
	{
		game->sol_index++;
	}
}

void	draw_exit(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	game->sol_frame++;
	while (y < game->max_y - 1)
	{
		while (x < game->max_x - 1)
		{
			if (game->map_ok[y][x] == 'E')
				exit_animation(game, y, x);
			x++;
		}
		x = 0;
		y++;
	}
}

int	update(t_game *game)
{
	t_collectible	*col;
	int				i;

	i = 0;
	game->nb_frames++;
	clear_sprites(game);
	detect_key(game);
	draw_tree(game);
	while (i < game->collectibles_numbers)
	{
		col = &game->collectibles[i];
		if (game->nb_frames % 35 == 0)
		{
			col->sprite_index++;
			col->sprite_index = col->sprite_index % 2;
		}
		i++;
	}
	draw_sprite(game, game->sprites_m[game->sprite_mechant], 100, 100);
	update_player(game);
	mlx_put_image_to_window(game->mlx, game->win, game->screen, 0, 0);
	if (game->nb_frames % 64 == 0)
	{
		game->sprite_mechant++;
		game->sprite_mechant = game->sprite_mechant % 4;
	}
	return (0);
}
