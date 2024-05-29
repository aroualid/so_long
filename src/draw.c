/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:34:32 by aroualid          #+#    #+#             */
/*   Updated: 2024/05/29 15:56:40 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_text(t_game *game, t_img *img, int x, int y)
{
	int				i;
	int				j;
	unsigned int	color;

	i = 0;
	while (i < img->width * 4)
	{
		j = -1;
		while (++j < img->height * 4)
		{
			if (j + y < 0 || j + y >= (4 * game->max_y * 32)
				|| i + x < 0 || i + x >= (4 * game->max_x * 32))
				continue ;
			color = ((int *)img->data)[(int)
				(j / 4) *(img->width) + (int)(i / 4)];
			if (color == 0xFF000000)
				continue ;
			((int *)game->screen->data)[(y + j)
				* game->screen->width + (x + i)] = color;
		}
		i++;
	}
}

void	draw_touch(t_game *game, t_img *img, int x, int y)
{
	int				i;
	int				j;
	unsigned int	color;

	i = 0;
	while (i < img->width)
	{
		j = -1;
		while (++j < img->height)
		{
			if (j + y < 0 || j + y >= (game->max_y * 32)
				|| i + x < 0 || i + x >= (game->max_x * 32))
				continue ;
			color = ((int *)img->data)[(int)
				(j) *(img->width) + (int)(i)];
			if (color == 0xFF000000)
				continue ;
			((int *)game->screen->data)[(y + j)
				* game->screen->width + (x + i)] = color;
		}
		i++;
	}
}
