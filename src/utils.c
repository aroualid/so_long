/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:50:58 by aroualid          #+#    #+#             */
/*   Updated: 2024/05/28 13:45:36 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	free_sprite(game->sprites_duck_wait, 6, game);
	free_sprite(game->correct_sprites, 6, game);
	free_sprite(game->reverse_sprites, 6, game);
	free_sprite(game->font_1, 2, game);
	free_sprite(game->num, 10, game);
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
