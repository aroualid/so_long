/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:50:58 by aroualid          #+#    #+#             */
/*   Updated: 2024/05/29 16:05:24 by aroualid         ###   ########.fr       */
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

uint32_t	xorshift32(t_xorshift32_state *state)
{
	uint32_t	x;

	x = state->a;
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
	return (state->a = x);
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

void	check_load(t_game *game)
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
	game->check_load = 1;
}
