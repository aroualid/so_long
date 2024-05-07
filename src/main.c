/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:23:05 by aroualid          #+#    #+#             */
/*   Updated: 2024/05/07 14:56:20 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../pars/so_long_pars.h"
#include <stdint.h>

int	main(int ac, char **av)
{
	t_game		game;
	int			i;
	void		*p;

	game = (t_game){0};
	if (pars(ac, av, &game) != 0)
	{
		i = 0;
		p = malloc(1);
		game.rand.a = (uint32_t)(unsigned long) p;
		free(p);
		game.scale = SCALE;
		game.player.x = game.pp_x * game.scale * 32;
		game.player.y = game.pp_y * game.scale * 32;
		init_mlx_settings(&game, game.scale * game.max_x * 32, game.scale * game.max_y * 32);
		game.last_key = 1;
		load_fruit(&game);
		load_duck(&game);
		load_mechant(&game);
		load_duck_wait(&game);
		load_duck_wait_reverse(&game);
		load_duck_reverse(&game);
		load_exit(&game);
		game.tree = load_sprite(game.mlx, "textures/tree3.xpm");
		game.collectibles_numbers = game.col_numbers;
		game.col_num = game.collectibles_numbers;
		printf("%i\n", game.col_num);
		game.collectibles = malloc(sizeof(t_collectible) * game.collectibles_numbers);
		while (i < game.collectibles_numbers)
		{
			generate_random_fruit(&game, i);
			i++;
		}
		mlx_loop_hook(game.mlx, update, &game);
		mlx_hook(game.win, KeyPress, KeyPressMask, key_pressed, &game);
		mlx_hook(game.win, KeyRelease, KeyReleaseMask, key_released, &game);
		mlx_hook(game.win, DestroyNotify, 0, close_game, &game);
		mlx_loop(game.mlx);
	}
}
