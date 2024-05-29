/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_font.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:23:19 by aroualid          #+#    #+#             */
/*   Updated: 2024/05/29 15:59:10 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	load_font_1(t_game *game)
{
	t_img	**ptr;
	int		i;

	i = 0;
	ptr = calloc(sizeof(t_img *), 2);
	ptr[0] = load_sprite(game->mlx, "textures/test.xpm");
	ptr[1] = load_sprite(game->mlx, "textures/test2.xpm");
	game->font_1 = ptr;
	while (i < 2)
	{
		if (ptr[i] == NULL)
			return (0);
		i++;
	}
	return (1);
}

int	load_num(t_game *game)
{
	t_img	**ptr;
	int		i;

	i = 0;
	ptr = calloc(sizeof(t_img *), 10);
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
	game->num = ptr;
	while (i < 10)
	{
		if (ptr[i] == NULL)
			return (0);
		i++;
	}
	return (1);
}

void	ft_put_nbr_to_win(t_game *game, int walk, int x)
{
	if (walk < 10)
		draw_text(game, game->num[walk],
			x + (game->scale * game->max_x * 32) - 20 * 3, 10);
	else if (walk < 100)
	{
		ft_put_nbr_to_win(game, walk / 10, x - 20 * 3);
		ft_put_nbr_to_win(game, walk % 10, x - 1 * 3);
	}
	else if (walk < 1000)
	{
		ft_put_nbr_to_win(game, walk / 100, x - 40 * 3);
		ft_put_nbr_to_win(game, (walk % 100) / 10, x - 20 * 3);
		ft_put_nbr_to_win(game, walk % 10, x - 1 * 3);
	}
	else
	{
		ft_put_nbr_to_win(game, walk / 1000, x - 60 * 3);
		ft_put_nbr_to_win(game, (walk % 1000) / 100, x - 40 * 3);
		ft_put_nbr_to_win(game, (walk % 100) / 10, x - 20 * 3);
		ft_put_nbr_to_win(game, walk % 10, x - 1 * 3);
	}
}

void	duck_space(t_game *game)
{
	int	x;

	x = ((game->x) / 2) - 400;
	if (game->nb_frames % 16 == 0)
	{
		game->font_index++;
		game->font_index = game->font_index % 2;
	}
	draw_text(game, game->font_1[game->font_index], x, 10);
}
