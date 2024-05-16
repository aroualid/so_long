/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:49:55 by aroualid          #+#    #+#             */
/*   Updated: 2024/05/16 16:26:41 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_img	*load_sprite(void *img, char *filename)
{
	int	width;
	int	height;

	if (!img || !filename)
		return (NULL);
	return (mlx_xpm_file_to_image(img, filename, &width, &height));
}

void	draw_sprite(t_game *game, t_img *img, int x, int y)
{
	int				i;
	int				j;
	unsigned int	color;

	i = 0;
	while (i < img->width * game->scale)
	{
		j = -1;
		while (++j < img->height * game->scale)
		{
			if (j + y < 0 || j + y >= (game->scale * game->max_y * 32)
				|| i + x < 0 || i + x >= (game->scale * game->max_x * 32))
				continue ;
			color = ((int *)img->data)[(int)
				(j / game->scale) * img->width + (int)(i / game->scale)];
			if (color == 0xFF000000)
				continue ;
			((int *)game->screen->data)[(y + j)
				* game->screen->width + (x + i)] = color;
		}
		i++;
	}
}

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
				(j / 4) * img->width + (int)(i / 4)];
			if (color == 0xFF000000)
				continue ;
			((int *)game->screen->data)[(y + j)
				* game->screen->width + (x + i)] = color;
		}
		i++;
	}
}



int	close_game(t_game *game)
{
	mlx_loop_end(game->mlx);
	return (0);
}

void	clear_sprites(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->screen->width * game->screen->height)
	{
		((int *) game->screen->data)[i] = 0;
		i++;
	}
}

int	init_mlx_settings(t_game *game, int x, int y)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_putstr_fd("Error\n❌the mlx pointer is NULL❌\n", 2);
		return (-1);
	}
	game->win = mlx_new_window(game->mlx, x, y, "so_long");
	game->screen = mlx_new_image(game->mlx, x, y);
	return (0);
}
