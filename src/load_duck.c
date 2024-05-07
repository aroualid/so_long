/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_duck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:46:57 by aroualid          #+#    #+#             */
/*   Updated: 2024/05/07 14:47:23 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_img	**load_duck(t_game *game)
{
	t_img	**ptr;

	ptr = malloc(sizeof(t_img *) * 6);
	ptr[0] = load_sprite(game->mlx, "textures/duck_1.xpm");
	ptr[1] = load_sprite(game->mlx, "textures/duck_2.xpm");
	ptr[2] = load_sprite(game->mlx, "textures/duck_3.xpm");
	ptr[3] = load_sprite(game->mlx, "textures/duck_4.xpm");
	ptr[4] = load_sprite(game->mlx, "textures/duck_5.xpm");
	ptr[5] = load_sprite(game->mlx, "textures/duck_6.xpm");
	game->sprites = ptr;
	game->correct_sprites = ptr;
	return (ptr);
}

t_img	**load_duck_reverse(t_game *game)
{
	t_img	**ptr;

	ptr = malloc(sizeof(t_img *) * 6);
	ptr[0] = load_sprite(game->mlx, "textures/2_duck_1.xpm");
	ptr[1] = load_sprite(game->mlx, "textures/2_duck_2.xpm");
	ptr[2] = load_sprite(game->mlx, "textures/2_duck_3.xpm");
	ptr[3] = load_sprite(game->mlx, "textures/2_duck_4.xpm");
	ptr[4] = load_sprite(game->mlx, "textures/2_duck_5.xpm");
	ptr[5] = load_sprite(game->mlx, "textures/2_duck_6.xpm");
	game->reverse_sprites = ptr;
	return (ptr);
}

t_img	**load_duck_wait(t_game *game)
{
	t_img	**ptr;

	ptr = malloc(sizeof(t_img *) * 6);
	ptr[0] = load_sprite(game->mlx, "textures/duck_wait_1.xpm");
	ptr[1] = load_sprite(game->mlx, "textures/duck_wait_2.xpm");
	ptr[2] = load_sprite(game->mlx, "textures/duck_wait_1.xpm");
	ptr[3] = load_sprite(game->mlx, "textures/duck_wait_2.xpm");
	ptr[4] = load_sprite(game->mlx, "textures/duck_wait_1.xpm");
	ptr[5] = load_sprite(game->mlx, "textures/duck_wait_2.xpm");
	game->sprites_duck_wait = ptr;
	return (ptr);
}

t_img	**load_duck_wait_reverse(t_game *game)
{
	t_img	**ptr;

	ptr = malloc(sizeof(t_img *) * 6);
	ptr[0] = load_sprite(game->mlx, "textures/2_duck_wait_1.xpm");
	ptr[1] = load_sprite(game->mlx, "textures/2_duck_wait_2.xpm");
	ptr[2] = load_sprite(game->mlx, "textures/2_duck_wait_1.xpm");
	ptr[3] = load_sprite(game->mlx, "textures/2_duck_wait_2.xpm");
	ptr[4] = load_sprite(game->mlx, "textures/2_duck_wait_1.xpm");
	ptr[5] = load_sprite(game->mlx, "textures/2_duck_wait_2.xpm");
	game->sprites_duck_wait_reverse = ptr;
	return (ptr);
}
