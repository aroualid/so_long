/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:47:03 by aroualid          #+#    #+#             */
/*   Updated: 2024/05/08 15:52:46 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../pars/so_long_pars.h"

void	load_game(t_game *game)
{
	int	x;
	int	y;

	x = game->scale * game->max_x * 32;
	y = game->scale * game->max_y * 32;
	game->scale = SCALE;
	game->player.x = game->pp_x * game->scale * 32;
	game->player.y = game->pp_y * game->scale * 32;
	init_mlx_settings(game, x, y);
	game->last_key = 1;
}

void	load(t_game *game)
{
	load_fruit(game);
	load_duck(game);
	load_mechant(game);
	load_duck_wait(game);
	load_duck_wait_reverse(game);
	load_duck_reverse(game);
	load_exit(game);
	game->tree = load_sprite(game->mlx, "textures/tree3.xpm");
}

int	main(int ac, char **av)
{
	t_game		game;

	game = (t_game){0};
	if (pars_bonus(ac, av, &game) != 0)
	{
		game.bonus = 1;
		load_game(&game);
		load(&game);
		random_p(&game);
		mlx_loop_hook(game.mlx, update, &game);
		mlx_hook(game.win, KeyPress, KeyPressMask, key_pressed, &game);
		mlx_hook(game.win, KeyRelease, KeyReleaseMask, key_released, &game);
		mlx_hook(game.win, DestroyNotify, 0, close_game, &game);
		mlx_loop(game.mlx);
	}
}