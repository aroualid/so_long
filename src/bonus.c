/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:47:03 by aroualid          #+#    #+#             */
/*   Updated: 2024/05/22 12:00:36 by aroualid         ###   ########.fr       */
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
	game->x = x;
	game->y = y;
	init_mlx_settings(game, x, y);
	game->player.x = game->pp_x * game->scale * 32;
	game->player.y = game->pp_y * game->scale * 32;
	game->ennemy.x = game->ennemy.x * game->scale * 32;
	game->ennemy.y = game->ennemy.y * game->scale * 32;
	game->last_key = 1;
}

void	load(t_game *game)
{
	load_fruit(game);
	load_duck(game);
	load_duck_wait(game);
	load_duck_wait_reverse(game);
	load_duck_reverse(game);
	load_exit(game);
	load_font_1(game);
	load_num(game);
	load_touch(game);
	load_mechant(game);
	game->tree = load_sprite(game->mlx, "textures/tree3.xpm");
}



int	main(int ac, char **av)
{
	t_game		game;

	game = (t_game){0};
	if (pars_bonus(ac, av, &game) != 0)
	{
		game.bonus = 1;
		if ((1920 / (game.max_x * 32)) - (1080 / (game.max_y * 32)) > 0)
			game.scale = 1080 / (game.max_y * 32);
		else
			game.scale = 1920 / (game.max_x * 32);
		if (game.max_y > 30 || game.max_x >= 60 || game.scale >= 5)
			return (ft_printf("%s\n", "INVALID MAP"));
		load_game(&game);
		load(&game);
		random_p(&game);
		mlx_loop_hook(game.mlx, update, &game);
		mlx_hook(game.win, KeyPress, KeyPressMask, key_pressed, &game);
		mlx_hook(game.win, KeyRelease, KeyReleaseMask, key_released, &game);
		mlx_hook(game.win, DestroyNotify, 0, close_game, &game);
		mlx_loop(game.mlx);
		free_all(&game);
	}
}
