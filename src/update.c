/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:53:03 by aroualid          #+#    #+#             */
/*   Updated: 2024/05/29 15:48:36 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	exit_animation(t_game *game, int y, int x)
{
	int	x_scale;
	int	y_scale;

	x_scale = x * 32 * game->scale;
	y_scale = y * 32 * game->scale;
	if (game->sol_frame % 96 == 0 && game->sol_index < 3)
	{
		game->sol_index++;
	}
	draw_sprite(game, game->sol[game->sol_index], x_scale, y_scale);
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

void	draw_key(t_game *game)
{
	draw_touch(game, game->a[game->a_ind], (5), 50);
	draw_touch(game, game->s[game->s_ind], (43), 50);
	draw_touch(game, game->d[game->d_ind], (81), 50);
	draw_touch(game, game->w[game->w_ind], (43), 10);
}

int	update(t_game *game)
{
	t_collectible	*col;
	int				i;

	i = 0;
	game->nb_frames++;
	clear_sprites(game);
	detect_key(game);
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
	update_player(game);
	draw_key(game);
	if (game->bonus == 1)
		update_ennemy(game);
	mlx_put_image_to_window(game->mlx, game->win, game->screen, 0, 0);
	return (0);
}
