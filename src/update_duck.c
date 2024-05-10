/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_duck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:24:54 by aroualid          #+#    #+#             */
/*   Updated: 2024/05/10 10:33:39 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	win_game(t_game *game)
{
	t_player	*play;
	int			x_ex;
	int			y_ex;
	int			scale;

	scale = 32 * game->scale;
	play = &game->player;
	y_ex = play->y + 16 * game->scale;
	x_ex = play->x + 16 * game->scale;
	if (game->map_ok[y_ex / scale][x_ex / scale] == 'E')
	{
		if(game->col_num == 0 && game->sol_index >= 3)
			mlx_loop_end(game->mlx);
	}
}

void	collect_fruit(t_game *game)
{
	t_player	*play;
	int			x_fruit;
	int			y_fruit;
	int			scale;

	scale = 32 * game->scale;
	play = &game->player;
	y_fruit = play->y + 16 * game->scale;
	x_fruit = play->x + 16 * game->scale;
	if (game->map_ok[y_fruit / scale][x_fruit / scale] == 'C')
	{
		game->col_num--;
		printf("%i\n", game->col_num);
		game->map_ok[y_fruit / scale][x_fruit / scale] = 'V';
	}
	if (game->col_num == 0)
		draw_exit(game);
}

void	duck_wait(t_game *game)
{
	if (game->last_key == 1)
		game->sprites = game->sprites_duck_wait;
	else if (game->last_key == 2)
		game->sprites = game->sprites_duck_wait_reverse;
	if (game->nb_frames % 96 == 0)
	{
		game->sprite_index++;
		game->sprite_index = game->sprite_index % 6;
	}
}

int	update_player(t_game *game)
{
	t_player	*play;

	play = &game->player;
	game->nb_frames++;
	detect_key(game);
	if (game->key_w || game->key_s || game->key_d || game->key_a)
		walk_animation(game);
	if (game->key_w && play->y >= 0)
		player_key_w(game);
	if (game->key_s && play->y <= game->scale * game->max_y * 32 - 32 * SCALE)
		player_key_s(game);
	if (game->key_a && play->x >= 0)
		player_key_a(game);
	if (game->key_d && play->x <= game->scale * game->max_x * 32 - 32 * SCALE)
		player_key_d(game);
	else if (game->key_w != 1 && game->key_s != 1
		&& game->key_d != 1 && game->key_a != 1)
		duck_wait(game);
	collect_fruit(game);
	win_game(game);
	draw_sprite(game, game->sprites[game->sprite_index], play->x, play->y);
	return (0);
}
