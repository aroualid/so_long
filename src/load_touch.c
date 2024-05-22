/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_touch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:32:39 by aroualid          #+#    #+#             */
/*   Updated: 2024/05/22 14:20:35 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_d(t_game *game)
{
	t_img	**ptr;

	ptr = malloc(sizeof(t_img *) * 2);
	ptr[1] = load_sprite(game->mlx, "textures/d_light.xpm");
	ptr[0] = load_sprite(game->mlx, "textures/d_dark.xpm");
	game->d = ptr;
}

void	load_a(t_game *game)
{
	t_img	**ptr;

	ptr = malloc(sizeof(t_img *) * 2);
	ptr[1] = load_sprite(game->mlx, "textures/a_light.xpm");
	ptr[0] = load_sprite(game->mlx, "textures/a_dark.xpm");
	game->a = ptr;
}

void	load_w(t_game *game)
{
	t_img	**ptr;

	ptr = malloc(sizeof(t_img *) * 2);
	ptr[1] = load_sprite(game->mlx, "textures/w_light.xpm");
	ptr[0] = load_sprite(game->mlx, "textures/w_dark.xpm");
	game->w = ptr;
}

void	load_s(t_game *game)
{
	t_img	**ptr;

	ptr = malloc(sizeof(t_img *) * 2);
	ptr[1] = load_sprite(game->mlx, "textures/s_light.xpm");
	ptr[0] = load_sprite(game->mlx, "textures/s_dark.xpm");
	game->s = ptr;
}

void	load_touch(t_game *game)
{
	load_w(game);
	load_a(game);
	load_s(game);
	load_d(game);
}
