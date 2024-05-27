/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duck_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:48:17 by aroualid          #+#    #+#             */
/*   Updated: 2024/05/27 16:50:39 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	player_key_w(t_game *game)
{
	detect_key(game);
	if (wall_col(game, game->player.x, game->player.y - game->scale))
		return ;
	else if (wall_col(game, game->player.x,
			game->player.y - (game->scale * (5 - game->scale))))
		return ;
	if (game->last_key == 1)
		game->sprites = game->correct_sprites;
	else if (game->last_key == 2)
		game->sprites = game->reverse_sprites;
	if (game->key_space)
		game->player.y -= game->scale * (5 - game->scale);
	else
		game->player.y -= game->scale;
	if (game->key_w == 1 && game->key_s != 1)
		game->walk+=2;
}

void	player_key_s(t_game *game)
{
	detect_key(game);
	if (wall_col(game, game->player.x, game->player.y + game->scale))
		return ;
	else if (wall_col(game, game->player.x,
			game->player.y + game->scale * (5 - game->scale)))
		return ;
	if (game->last_key == 1)
		game->sprites = game->correct_sprites;
	else if (game->last_key == 2)
		game->sprites = game->reverse_sprites;
	if (game->key_space)
		game->player.y += game->scale* (5 - game->scale);
	else
		game->player.y += game->scale;
	if (game->key_s == 1 && game->key_w != 1)
		game->walk+=2;
}

void	player_key_a(t_game *game)
{
	detect_key(game);
	if (wall_col(game, game->player.x - game->scale, game->player.y))
		return ;
	else if (wall_col(game, game->player.x - game->scale * (5 - game->scale),
			game->player.y))
		return ;
	game->sprites = game->reverse_sprites;
	if (game->key_space)
		game->player.x -= game->scale * (5 - game->scale);
	else
		game->player.x -= game->scale;
	if (game->key_a == 1 && game->key_d != 1)
		game->walk+=2;
}

void	player_key_d(t_game *game)
{
	detect_key(game);
	if (wall_col(game, game->player.x + game->scale, game->player.y))
		return;
	else if (wall_col(game, game->player.x + game->scale * (5 - game->scale),
			game->player.y))
		return ;
	game->sprites = game->correct_sprites;
	if (game->key_space)
		game->player.x += game->scale * (5 - game->scale);
	else
		game->player.x += game->scale;
	if (game->key_d == 1 && game->key_a != 1)
		game->walk+=2;
}

void	walk_animation(t_game *game)
{
	if (game->nb_frames % 32 == 0)
	{
		game->sprite_index++;
		game->sprite_index = game->sprite_index % 6;
	}
}
