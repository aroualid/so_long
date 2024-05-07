/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:57:02 by aroualid          #+#    #+#             */
/*   Updated: 2024/05/07 16:14:59 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_sol(t_game *game, int y, int x)
{
	draw_sprite(game, game->sol[0], x * game->scale * 32, y * game->scale * 32);
}

void	draw_wall(t_game *game, int y, int x)
{
	draw_sprite(game, game->tree, x * game->scale * 32, y * game->scale * 32);
}

void	draw_tree(t_game *game)
{
	int	x;
	int	y;
	int	t;
	int	collectible_number;

	collectible_number = 0;
	x = 0;
	y = 0;
	while (y < game->max_y)
	{
		while (x < game->max_x)
		{
			if (game->map_ok[y][x] == 'V')
				collectible_number++;
			if (game->map[y][x] == 'X' || game->map[y][x] == '1')
				draw_sol(game, y, x);
			if (game->map_ok[y][x] == '1')
				draw_wall(game, y ,x);
			if (game->map_ok[y][x] == 'C')
			{
				t = game->collectibles[collectible_number].sprite_index;
				draw_sprite(game, game->collectibles[collectible_number].fruit_sprites[t], x * game->scale * 32, y * game->scale * 32);
				collectible_number++;
			}
			x++;
		}
		y++;
		x = 0;
	}
}

