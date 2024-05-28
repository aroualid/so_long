/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:01:01 by aroualid          #+#    #+#             */
/*   Updated: 2024/05/28 19:08:26 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_all(t_game *game)
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
			if (game->map[y][x] == 'X' || game->map[y][x] == '1' 
				|| game->map_ok[y][x] == '0')
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
