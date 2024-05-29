/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:47:40 by aroualid          #+#    #+#             */
/*   Updated: 2024/05/29 23:55:56 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	load_tree(t_game *game)
{
	t_img	**ptr;

	ptr = malloc(sizeof(t_img *) * 1);
	ptr[0] = load_sprite(game->mlx, "textures/tree3.xpm");
	game->tree = ptr;
	if (ptr[0] == NULL)
		return (0);
	return (1);
}

int	load_mechant(t_game *game)
{
	t_img	**ptr;
	int		i;

	i = 0;
	ptr = malloc(sizeof(t_img *) * 4);
	ptr[0] = load_sprite(game->mlx, "textures/mechant_1.xpm");
	ptr[1] = load_sprite(game->mlx, "textures/mechant_2.xpm");
	ptr[2] = load_sprite(game->mlx, "textures/mechant_3.xpm");
	ptr[3] = load_sprite(game->mlx, "textures/mechant_4.xpm");
	game->sprites_m = ptr;
	while (i < 4)
	{
		if (ptr[i] == NULL)
			return (0);
		i++;
	}
	return (1);
}

int	load_fruit(t_game *game)
{
	game->load_fruit = malloc(sizeof(t_img **) * 5);
	game->load_fruit[0] = load_apple(game);
	game->load_fruit[1] = load_lemon(game);
	game->load_fruit[2] = load_pear(game);
	game->load_fruit[3] = load_strawberry(game);
	game->load_fruit[4] = load_watermelon(game);
	return (1);
}

void	generate_random_fruit(t_game *game, int index)
{
	uint32_t	random;

	random = xorshift32(&game->rand) % 5;
	game->collectibles[index].sprite_index = 0;
	game->collectibles[index].fruit_sprites = game->load_fruit[random];
}

int	load_exit(t_game *game)
{
	t_img	**ptr;

	ptr = malloc(sizeof(t_img **) * 4);
	ptr[0] = load_sprite(game->mlx, "textures/traps1.xpm");
	ptr[1] = load_sprite(game->mlx, "textures/traps2.xpm");
	ptr[2] = load_sprite(game->mlx, "textures/traps3.xpm");
	ptr[3] = load_sprite(game->mlx, "textures/traps4.xpm");
	game->sol = ptr;
	return (1);
}
