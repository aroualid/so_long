/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:25:14 by aroualid          #+#    #+#             */
/*   Updated: 2024/05/29 15:44:49 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	handle_load_fruit_failure(t_game *game)
{
	free_fruit(game);
	game->check_load = 0;
}

void	handle_load_duck_failure(t_game *game)
{
	free_sprite(game->correct_sprites, 6, game);
	free_fruit(game);
	game->check_load = 0;
}

void	handle_load_duck_wait_failure(t_game *game)
{
	free_sprite(game->correct_sprites, 6, game);
	free_sprite(game->sprites_duck_wait, 6, game);
	free_fruit(game);
	game->check_load = 0;
}

void	handle_load_duck_wait_reverse_failure(t_game *game)
{
	free_sprite(game->correct_sprites, 6, game);
	free_sprite(game->sprites_duck_wait_reverse, 6, game);
	free_sprite(game->sprites_duck_wait, 6, game);
	free_fruit(game);
	game->check_load = 0;
}

void	handle_load_duck_reverse_failure(t_game *game)
{
	free_sprite(game->correct_sprites, 6, game);
	free_sprite(game->reverse_sprites, 6, game);
	free_sprite(game->sprites_duck_wait_reverse, 6, game);
	free_sprite(game->sprites_duck_wait, 6, game);
	free_sprite(game->sprites, 6, game);
	free_fruit(game);
	game->check_load = 0;
}
