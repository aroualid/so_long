/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_touch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:32:39 by aroualid          #+#    #+#             */
/*   Updated: 2024/05/30 00:09:29 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	load_d(t_game *game)
{
	t_img	**ptr;
	int		i;

	i = 0;
	ptr = malloc(sizeof(t_img *) * 2);
	if (!ptr)
		return (0);
	ptr[1] = load_sprite(game->mlx, "textures/d_light.xpm");
	ptr[0] = load_sprite(game->mlx, "textures/d_dark.xpm");
	while (i < 2)
	{
		if (ptr[i] == NULL)
			return (0);
		i++;
	}
	game->d = ptr;
	return (1);
}

int	load_a(t_game *game)
{
	t_img	**ptr;
	int		i;

	i = 0;
	ptr = malloc(sizeof(t_img *) * 2);
	if (!ptr)
		return (0);
	ptr[1] = load_sprite(game->mlx, "textures/a_light.xpm");
	ptr[0] = load_sprite(game->mlx, "textures/a_dark.xpm");
	while (i < 2)
	{
		if (ptr[i] == NULL)
			return (0);
		i++;
	}
	game->a = ptr;
	return (1);
}

int	load_w(t_game *game)
{
	t_img	**ptr;
	int		i;

	i = 0;
	ptr = malloc(sizeof(t_img *) * 2);
	if (!ptr)
		return (0);
	ptr[1] = load_sprite(game->mlx, "textures/w_light.xpm");
	ptr[0] = load_sprite(game->mlx, "textures/w_dark.xpm");
	while (i < 2)
	{
		if (ptr[i] == NULL)
			return (0);
		i++;
	}
	game->w = ptr;
	return (1);
}

int	load_s(t_game *game)
{
	t_img	**ptr;
	int		i;

	i = 0;
	ptr = malloc(sizeof(t_img *) * 2);
	if (!ptr)
		return (0);
	ptr[1] = load_sprite(game->mlx, "textures/s_light.xpm");
	ptr[0] = load_sprite(game->mlx, "textures/s_dark.xpm");
	while (i < 2)
	{
		if (ptr[i] == NULL)
			return (0);
		i++;
	}
	game->s = ptr;
	return (1);
}

int	load_touch(t_game *game)
{
	load_w(game);
	load_a(game);
	load_s(game);
	load_d(game);
	return (1);
}
