/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duck_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:48:17 by aroualid          #+#    #+#             */
/*   Updated: 2024/05/12 19:28:35 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	player_key_w(t_game *game)
{
	detect_key(game);
	if (wall_col(game, game->player.x, game->player.y - game->scale))
		return ;
	if (game->last_key == 1)
		game->sprites = game->correct_sprites;
	else if (game->last_key == 2)
		game->sprites = game->reverse_sprites;
	if (game->key_space)
	{
		game->player.y -= game->scale * 2;
	}
	else
		game->player.y -= game->scale;
}

void	player_key_s(t_game *game)
{
	detect_key(game);
	if (wall_col(game, game->player.x, game->player.y + game->scale))
		return ;
	if (game->last_key == 1)
		game->sprites = game->correct_sprites;
	else if (game->last_key == 2)
		game->sprites = game->reverse_sprites;
	if (game->key_space)
	{
		duck_space(game);
		game->player.y += game->scale * 2;
	}
	else
		game->player.y += game->scale;
}

void	player_key_a(t_game *game)
{
	detect_key(game);
	if (wall_col(game, game->player.x - game->scale, game->player.y))
		return ;
	game->sprites = game->reverse_sprites;
	if (game->key_space)
	{
		game->player.x -= game->scale * 2;
	}
	else
		game->player.x -= game->scale;
}

void	player_key_d(t_game *game)
{
	detect_key(game);
	if (wall_col(game, game->player.x + game->scale, game->player.y))
		return ;
	game->sprites = game->correct_sprites;
	if (game->key_space)
	{
		game->player.x += game->scale * 2;
	}
	else
		game->player.x += game->scale;

}

void	walk_animation(t_game *game)
{
	if (game->nb_frames % 32 == 0)
	{
		game->sprite_index++;
		game->sprite_index = game->sprite_index % 6;
	}
}
