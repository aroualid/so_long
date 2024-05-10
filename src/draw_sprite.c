/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:57:02 by aroualid          #+#    #+#             */
/*   Updated: 2024/05/10 13:45:52 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_sol(t_game *game, int y, int x)
{
	draw_sprite(game, game->sol[0], x * game->scale * 32, y * game->scale * 32);
}

void	draw_wall(t_game *game, int y, int x)
{
	game->wall.x = x * game->scale * 32;
	game->wall.y = y * game->scale * 32;
	draw_sprite(game, game->tree, x * game->scale * 32, y * game->scale * 32);
}

bool	collide(t_wall *wall, int x, int y, t_game *game)
{
	return (x < wall->x + 27 * game->scale
		&& x + 27 * game->scale > wall->x
		&& y < wall->y + 25 * game->scale
		&& y + 29 * game->scale > wall->y);
}

int	draw_fruit(t_game *game, int y, int x, int collectible_number)
{
	int	t;

	t = game->collectibles[collectible_number].sprite_index;
	draw_sprite(game, game->collectibles[collectible_number].fruit_sprites[t], \
		x * game->scale * 32, y * game->scale * 32);
	collectible_number++;
	return (collectible_number);
}

bool	wall_col(t_game *game, int x2, int y2)
{
	int		x;
	int		y;
	t_wall	wall;

	x = 0;
	y = 0;
	while (y < game->max_y)
	{
		while (x < game->max_x)
		{
			wall.x = x * 32 * game->scale;
			wall.y = y * 32 * game->scale;
			if (game->map_ok[y][x] == '1'
				&& collide(&wall, x2, y2, game) == true)
				return (true);
			x++;
		}
		y++;
		x = 0;
	}
	return (false);
}

void	draw_tree(t_game *game)
{
	int	x;
	int	y;
	int	collectible_number;

	collectible_number = 0;
	x = -1;
	y = 0;
	while (y < game->max_y)
	{
		while (x++ < game->max_x)
		{
			if (game->map_ok[y][x] == 'V')
				collectible_number++;
			if (game->map[y][x] == 'X' || game->map[y][x] == '1')
				draw_sol(game, y, x);
			if (game->map_ok[y][x] == '1')
				draw_wall(game, y, x);
			if (game->map_ok[y][x] == 'C')
				collectible_number = draw_fruit(game, y, x, collectible_number);
		}
		y++;
		x = -1;
	}
}
