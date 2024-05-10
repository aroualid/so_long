/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:47:40 by aroualid          #+#    #+#             */
/*   Updated: 2024/05/10 10:33:50 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_img	**load_mechant(t_game *game)
{
	t_img	**ptr;

	ptr = malloc(sizeof(t_img *) * 4);
	ptr[0] = load_sprite(game->mlx, "textures/mechant_1.xpm");
	ptr[1] = load_sprite(game->mlx, "textures/mechant_2.xpm");
	ptr[2] = load_sprite(game->mlx, "textures/mechant_3.xpm");
	ptr[3] = load_sprite(game->mlx, "textures/mechant_4.xpm");
	game->sprites_m = ptr;
	return (ptr);
}

void	load_fruit(t_game *game)
{
	game->load_fruit = malloc(sizeof(t_img **) * 5);
	game->load_fruit[0] = load_apple(game);
	game->load_fruit[1] = load_lemon(game);
	game->load_fruit[2] = load_pear(game);
	game->load_fruit[3] = load_strawberry(game);
	game->load_fruit[4] = load_watermelon(game);
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

void	generate_random_fruit(t_game *game, int index)
{
	uint32_t	random;
	uint32_t	i;

	i = 5;
	random = xorshift32(&game->rand) % 5;
	game->collectibles[index].sprite_index = 0;
	game->collectibles[index].fruit_sprites = game->load_fruit[random];
}

t_img	**load_exit(t_game *game)
{
	t_img	**ptr;

	ptr = malloc(sizeof(t_img **) * 4);
	ptr[0] = load_sprite(game->mlx, "textures/traps1.xpm");
	ptr[1] = load_sprite(game->mlx, "textures/traps2.xpm");
	ptr[2] = load_sprite(game->mlx, "textures/traps3.xpm");
	ptr[3] = load_sprite(game->mlx, "textures/traps4.xpm");
	game->sol = ptr;
	return (ptr);
}
