/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_fruit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:24:56 by aroualid          #+#    #+#             */
/*   Updated: 2024/05/28 18:30:47 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_img	**load_apple(t_game *game)
{
	t_img	**ptr;
	int		i;

	i = 0;
	ptr = malloc(sizeof(t_img *) * 2);
	ptr[0] = load_sprite(game->mlx, "textures/orange_1.xpm");
	ptr[1] = load_sprite(game->mlx, "textures/orange_2.xpm");
	game->sprites_apple = ptr;
	while (i < 2)
	{
		if (ptr[i] == NULL)
			return (0);
		i++;
	}
	return (ptr);
}

t_img	**load_lemon(t_game *game)
{
	t_img	**ptr;
	int		i;

	i = 0;
	ptr = malloc(sizeof(t_img *) * 2);
	ptr[0] = load_sprite(game->mlx, "textures/lemon_1.xpm");
	ptr[1] = load_sprite(game->mlx, "textures/lemon_2.xpm");
	game->sprites_lemon = ptr;
	while (i < 2)
	{
		if (ptr[i] == NULL)
			return (0);
		i++;
	}
	return (ptr);
}

t_img	**load_pear(t_game *game)
{
	t_img	**ptr;
	int		i;

	i = 0;
	ptr = malloc(sizeof(t_img *) * 2);
	ptr[0] = load_sprite(game->mlx, "textures/pear_1.xpm");
	ptr[1] = load_sprite(game->mlx, "textures/pear_2.xpm");
	game->sprites_pear = ptr;
	while (i < 2)
	{
		if (ptr[i] == NULL)
			return (0);
		i++;
	}
	return (ptr);
}

t_img	**load_strawberry(t_game *game)
{
	t_img	**ptr;
	int		i;

	i = 0;
	ptr = malloc(sizeof(t_img *) * 2);
	ptr[0] = load_sprite(game->mlx, "textures/strawberry_1.xpm");
	ptr[1] = load_sprite(game->mlx, "textures/strawberry_2.xpm");
	game->sprites_strawberry = ptr;
	while (i < 2)
	{
		if (ptr[i] == NULL)
			return (0);
		i++;
	}
	return (ptr);
}

t_img	**load_watermelon(t_game *game)
{
	t_img	**ptr;
	int		i;

	i = 0;
	ptr = malloc(sizeof(t_img *) * 2);
	ptr[0] = load_sprite(game->mlx, "textures/watermelon_1.xpm");
	ptr[1] = load_sprite(game->mlx, "textures/watermelon_2.xpm");
	game->sprites_watermelon = ptr;
	while (i < 2)
	{
		if (ptr[i] == NULL)
			return (0);
		i++;
	}
	return (ptr);
}
