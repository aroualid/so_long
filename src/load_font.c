/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_font.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:23:19 by aroualid          #+#    #+#             */
/*   Updated: 2024/05/15 12:07:09 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_font_1(t_game *game)
{
	t_img	**ptr;

	ptr = malloc(sizeof(t_img *) * 2);
	ptr[0] = load_sprite(game->mlx, "textures/test.xpm");
	ptr[1] = load_sprite(game->mlx, "textures/test2.xpm");
	game->font_1  = ptr;
}

void	duck_space(t_game *game)
{
	int x;

	x = ((game->scale * game->max_x * 32) / 2) - 75 * game->scale;
	if (game->nb_frames % 16 == 0)
	{
		game->font_index++;
		game->font_index = game->font_index%2;
	}
	draw_sprite(game, game->font_1[game->font_index], x, 5);
}
