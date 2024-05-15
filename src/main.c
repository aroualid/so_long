/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:23:05 by aroualid          #+#    #+#             */
/*   Updated: 2024/05/15 11:25:36 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../pars/so_long_pars.h"
#include <stdint.h>

void	load_game(t_game *game)
{
	int	x;
	int	y;

	x = game->scale * game->max_x * 32;
	y = game->scale * game->max_y * 32;
	init_mlx_settings(game, x, y);
	game->player.x = game->pp_x * game->scale * 32;
	game->player.y = game->pp_y * game->scale * 32;
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
	game->tree = load_sprite(game->mlx, "textures/tree3.xpm");
}

void	random_p(t_game *game)
{
	void	*p;
	int		i;

	i = 0;
	p = malloc(1);
	game->rand.a = (uint32_t)(unsigned long) p;
	free(p);
	game->collectibles_numbers = game->col_numbers;
	game->col_num = game->collectibles_numbers;
	game->collectibles = malloc(sizeof(t_collectible) \
		* game->collectibles_numbers);
	while (i < game->collectibles_numbers)
	{
		generate_random_fruit(game, i);
		i++;
	}
}

void	free_sprite(t_img **ptr, int index, t_game *game)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (ptr[i])
		{
			mlx_destroy_image(game->mlx, ptr[i]);
			ptr[i] = NULL;
		}
		i++;
	}
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

void	free_fruit(t_game *game)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		free_sprite(game->load_fruit[i], 2, game);
		i++;
	}
	free(game->load_fruit);
}

void	free_all(t_game *game)
{
	free_sprite(game->sol, 4, game);
	free_sprite(game->sprites_duck_wait_reverse, 6, game);
	//free_sprite(game->sprites_duck_wait, game->sprite_duck_wait, game);
	free_sprite(game->sprites_duck_wait, 6, game);
	//free_sprite(game->sprites, 6, game);
	free_sprite(game->correct_sprites, 6, game);
	free_sprite(game->reverse_sprites, 6, game);
	free_sprite(game->font_1, 2, game);
	free_fruit(game);
	if (game->collectibles)
	{
		free(game->collectibles);
		game->collectibles = NULL;
	}
	mlx_destroy_image(game->mlx, game->tree);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_image(game->mlx, game->screen);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

int	main(int ac, char **av)
{
	t_game		game;

	game = (t_game){0};
	if (pars(ac, av, &game) != 0)
	{
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
	free_map(&game);

}
