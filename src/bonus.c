/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:47:03 by aroualid          #+#    #+#             */
/*   Updated: 2024/05/29 16:09:42 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../pars/so_long_pars.h"

void	check_load_bonus(t_game *game)
{
	if (load_fruit(game) == 0)
		return (handle_load_fruit_failure(game));
	if (load_duck(game) == 0)
		return (handle_load_duck_failure(game));
	if (load_duck_wait(game) == 0)
		return (handle_load_duck_wait_failure(game));
	if (load_duck_wait_reverse(game) == 0)
		return (handle_load_duck_wait_reverse_failure(game));
	if (load_duck_reverse(game) == 0)
		return (handle_load_duck_reverse_failure(game));
	if (load_exit(game) == 0)
		return (handle_load_exit_failure(game));
	if (load_font_1(game) == 0)
		return (handle_load_font_1_failure(game));
	if (load_num(game) == 0)
		return (handle_load_num_failure(game));
	if (load_touch(game) == 0)
		return (handle_load_touch_failure(game));
	if (load_tree(game) == 0)
		return (handle_load_tree_failure(game));
	if (load_mechant(game) == 0)
		return (handle_load_ennemy_failure(game));
	game->check_load = 1;
}

int	init_mlx_settings_bonus(t_game *game, int x, int y)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_putstr_fd("Error\n❌the mlx pointer is NULL❌\n", 2);
		return (-1);
	}
	check_load_bonus(game);
	if (game->check_load == 0)
	{
		return (-1);
	}
	game->win = mlx_new_window(game->mlx, x, y, "so_long");
	game->screen = mlx_new_image(game->mlx, x, y);
	return (0);
}

void	load_game_bonus(t_game *game)
{
	int	x;
	int	y;

	x = game->scale * game->max_x * 32;
	y = game->scale * game->max_y * 32;
	game->x = x;
	game->y = y;
	init_mlx_settings_bonus(game, x, y);
	game->player.x = game->pp_x * game->scale * 32;
	game->player.y = game->pp_y * game->scale * 32;
	game->ennemy.x = game->ennemy.x * game->scale * 32;
	game->ennemy.y = game->ennemy.y * game->scale * 32;
	game->last_key = 1;
}

int	check_main(t_game *game)
{
	free_map(game);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	return (ft_printf("%s\n", "INVALID SPRITE"));
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
		load_game_bonus(&game);
		if (game.check_load == 0)
			return (check_main(&game));
		random_p(&game);
		mlx_loop_hook(game.mlx, update, &game);
		mlx_hook(game.win, KeyPress, KeyPressMask, key_pressed, &game);
		mlx_hook(game.win, KeyRelease, KeyReleaseMask, key_released, &game);
		mlx_hook(game.win, DestroyNotify, 0, close_game, &game);
		mlx_loop(game.mlx);
		free_all_bonus(&game);
	}
	free_map(&game);
}
