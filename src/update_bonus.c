/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:28:35 by aroualid          #+#    #+#             */
/*   Updated: 2024/05/28 14:31:42 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_enemy(t_game *game)
{
	draw_sprite(game, game->sprites_m[game->sprite_mechant],
		game->ennemy.x, game->ennemy.y);
	if (game->nb_frames % 64 == 0)
	{
		game->sprite_mechant++;
		game->sprite_mechant = game->sprite_mechant % 4;
	}
}

bool	collide_ennemy(t_game *game)
{
	return (game->player.x < game->ennemy.x + 16 * game->scale
		&& game->player.x + 16 * game->scale > game->ennemy.x
		&& game->player.y < game->ennemy.y + 16 * game->scale
		&& game->player.y + 16 * game->scale > game->ennemy.y);
}

void	update_ennemy(t_game *game)
{
	float	i;
	int		scale;

	scale = game->scale;
	if ((game->col_num != game->col_numbers)
		&& (game->ennemy.x - game->player.x < (game->max_x / 4) * 32 * scale)
		&& (game->player.x - game->ennemy.x < (game->max_x / 4) * 32 * scale)
		&& (game->ennemy.y - game->player.y < (game->max_y / 2) * 32 * scale)
		&& (game->player.y - game->ennemy.y < (game->max_y / 2) * 32 * scale))
	{
		i = 0.5 + ((float) game->scale / 2);
		if (game->ennemy.x > game->player.x)
			game->ennemy.x -= i;
		if (game->ennemy.y > game->player.y)
			game->ennemy.y -= i;
		if (game->ennemy.x < game->player.x)
			game->ennemy.x += i;
		if (game->ennemy.y < game->player.y)
			game->ennemy.y += i;
	}
	draw_enemy(game);
	if (collide_ennemy(game) == true)
		mlx_loop_end(game->mlx);
}
