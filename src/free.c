/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 09:23:43 by aroualid          #+#    #+#             */
/*   Updated: 2024/05/30 14:03:17 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(t_game *game)
{
	int	i;

	if (!game)
		return ;
	i = 0;
	while (i < game->max_y)
	{
		if (game->map[i])
		{
			free(game->map[i]);
			game->map[i] = NULL;
			free(game->map_ok[i]);
			game->map_ok[i] = NULL;
		}
		i++;
	}
	free(game->map);
	free(game->map_ok);
	close(game->i);
	close(game->k);
}

void	free_all(t_game *game)
{
	free_sprite(game->sol, 4, game);
	free_sprite(game->sprites_duck_wait_reverse, 6, game);
	free_sprite(game->sprites_duck_wait, 6, game);
	free_sprite(game->correct_sprites, 6, game);
	free_sprite(game->reverse_sprites, 6, game);
	free_sprite(game->font_1, 2, game);
	free_sprite(game->num, 10, game);
	free_sprite(game->w, 2, game);
	free_sprite(game->a, 2, game);
	free_sprite(game->s, 2, game);
	free_sprite(game->d, 2, game);
	free_fruit(game);
	free_sprite(game->tree, 1, game);
	if (game->collectibles)
	{
		free(game->collectibles);
		game->collectibles = NULL;
	}
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_image(game->mlx, game->screen);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

void	free_all_bonus(t_game *game)
{
	free_sprite(game->sol, 4, game);
	free_sprite(game->sprites_duck_wait_reverse, 6, game);
	free_sprite(game->sprites_duck_wait, 6, game);
	free_sprite(game->correct_sprites, 6, game);
	free_sprite(game->reverse_sprites, 6, game);
	free_sprite(game->font_1, 2, game);
	free_sprite(game->num, 10, game);
	free_sprite(game->w, 2, game);
	free_sprite(game->a, 2, game);
	free_sprite(game->s, 2, game);
	free_sprite(game->d, 2, game);
	free_fruit(game);
	free_sprite(game->tree, 1, game);
	free_sprite(game->sprites_m, 4, game);
	if (game->collectibles)
	{
		free(game->collectibles);
		game->collectibles = NULL;
	}
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_image(game->mlx, game->screen);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

void	handle_load_ennemy_failure(t_game *game)
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
	free_sprite(game->sprites_m, 4, game);
	game->check_load = 0;
}
