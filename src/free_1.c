/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:28:51 by aroualid          #+#    #+#             */
/*   Updated: 2024/05/29 15:46:04 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	handle_load_exit_failure(t_game *game)
{
	free_sprite(game->sol, 4, game);
	free_sprite(game->correct_sprites, 6, game);
	free_sprite(game->reverse_sprites, 6, game);
	free_sprite(game->sprites_duck_wait_reverse, 6, game);
	free_sprite(game->sprites_duck_wait, 6, game);
	free_fruit(game);
	game->check_load = 0;
}

void	handle_load_font_1_failure(t_game *game)
{
	free_sprite(game->font_1, 2, game);
	free_sprite(game->sol, 4, game);
	free_sprite(game->correct_sprites, 6, game);
	free_sprite(game->reverse_sprites, 6, game);
	free_sprite(game->sprites_duck_wait_reverse, 6, game);
	free_sprite(game->sprites_duck_wait, 6, game);
	free_fruit(game);
	game->check_load = 0;
}

void	handle_load_num_failure(t_game *game)
{
	free_sprite(game->num, 10, game);
	free_sprite(game->font_1, 2, game);
	free_sprite(game->sol, 4, game);
	free_sprite(game->correct_sprites, 6, game);
	free_sprite(game->reverse_sprites, 6, game);
	free_sprite(game->sprites_duck_wait_reverse, 6, game);
	free_sprite(game->sprites_duck_wait, 6, game);
	free_fruit(game);
	game->check_load = 0;
}

void	handle_load_touch_failure(t_game *game)
{
	free_sprite(game->w, 2, game);
	free_sprite(game->a, 2, game);
	free_sprite(game->s, 2, game);
	free_sprite(game->d, 2, game);
	free_sprite(game->num, 10, game);
	free_sprite(game->font_1, 2, game);
	free_sprite(game->sol, 4, game);
	free_sprite(game->correct_sprites, 6, game);
	free_sprite(game->reverse_sprites, 6, game);
	free_sprite(game->sprites_duck_wait_reverse, 6, game);
	free_sprite(game->sprites_duck_wait, 6, game);
	free_fruit(game);
	game->check_load = 0;
}

void	handle_load_tree_failure(t_game *game)
{
	free_sprite(game->w, 2, game);
	free_sprite(game->a, 2, game);
	free_sprite(game->s, 2, game);
	free_sprite(game->d, 2, game);
	free_sprite(game->num, 10, game);
	free_sprite(game->font_1, 2, game);
	free_sprite(game->sol, 4, game);
	free_sprite(game->correct_sprites, 6, game);
	free_sprite(game->reverse_sprites, 6, game);
	free_sprite(game->sprites_duck_wait_reverse, 6, game);
	free_sprite(game->sprites_duck_wait, 6, game);
	free_fruit(game);
	free_sprite(game->tree, 1, game);
	game->check_load = 0;
}
