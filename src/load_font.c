/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_font.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:23:19 by aroualid          #+#    #+#             */
/*   Updated: 2024/05/15 15:40:45 by aroualid         ###   ########.fr       */
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

void	load_num(t_game *game)
{
	t_img	**ptr;

	ptr = malloc(sizeof(t_img *) * 10);
	ptr[0] = load_sprite(game->mlx, "textures/0.xpm");
	ptr[1] = load_sprite(game->mlx, "textures/1.xpm");
	ptr[2] = load_sprite(game->mlx, "textures/2.xpm");
	ptr[3] = load_sprite(game->mlx, "textures/3.xpm");
	ptr[4] = load_sprite(game->mlx, "textures/4.xpm");
	ptr[5] = load_sprite(game->mlx, "textures/5.xpm");
	ptr[6] = load_sprite(game->mlx, "textures/6.xpm");
	ptr[7] = load_sprite(game->mlx, "textures/7.xpm");
	ptr[8] = load_sprite(game->mlx, "textures/8.xpm");
	ptr[9] = load_sprite(game->mlx, "textures/9.xpm");
	game->num  = ptr;
}


void	ft_put_nbr_to_win(t_game *game, int walk, int x)
{
	if (walk < 10)
		draw_sprite(game, game->num[walk], x + (game->scale * game->max_x * 32) - 10 * game->scale, 20);
	else if (walk < 100)
    {
        ft_put_nbr_to_win(game, walk / 10, x - 20 * game->scale);
        ft_put_nbr_to_win(game, walk % 10, x - 10 * game->scale);
    }
	else if (walk < 1000)
	{
		ft_put_nbr_to_win(game, walk / 100, x - 30 * game->scale);
		ft_put_nbr_to_win(game, (walk % 100) / 10, x - 20 * game->scale);
		ft_put_nbr_to_win(game, walk % 10, x - 10 * game->scale);
	}
	else
    {
        ft_put_nbr_to_win(game, walk / 1000, x - 40 * game->scale);
        ft_put_nbr_to_win(game, (walk % 1000) / 100, x - 30 * game->scale);
        ft_put_nbr_to_win(game, (walk % 100) / 10, x - 20 * game->scale);
        ft_put_nbr_to_win(game, walk % 10, x - 10 * game->scale);
    }
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
