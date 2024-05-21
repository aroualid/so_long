/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:53:03 by aroualid          #+#    #+#             */
/*   Updated: 2024/05/21 16:39:25 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	exit_animation(t_game *game, int y, int x)
{
	int	x_scale;
	int	y_scale;

	x_scale = x * 32 * game->scale;
	y_scale = y * 32 * game->scale;
	if (game->sol_frame % 96  == 0 && game->sol_index < 3)
	{
		game->sol_index++;
	}
	draw_sprite(game, game->sol[game->sol_index], x_scale, y_scale);
}

void	draw_enemy(t_game *game)
{
	draw_sprite(game, game->sprites_m[game->sprite_mechant], game->ennemy.x , game->ennemy.y);
	if (game->nb_frames % 64 == 0)
	{
		game->sprite_mechant++;
		game->sprite_mechant = game->sprite_mechant % 4;
	}
}

void	draw_exit(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	game->sol_frame++;
	while (y < game->max_y - 1)
	{
		while (x < game->max_x - 1)
		{
			if (game->map_ok[y][x] == 'E')
				exit_animation(game, y, x);
			x++;
		}
		x = 0;
		y++;
	}
}


/*static void	print_steps(t_game *game)
{
	char	*move;

	move = ft_itoa(game->walk / 20);
	mlx_string_put(game->mlx, game->win, 10 * game->scale,
		20 * game->scale, 0xFFFF00, "Nb de pas : ");
	mlx_string_put(game->mlx, game->win, 40 * game->scale,
		20 * game->scale, 0xFFFFF00, move);
}

*/

int	update(t_game *game)
{
	t_collectible	*col;
	int				i;

	i = 0;
	game->nb_frames++;
	clear_sprites(game);
	detect_key(game);
	while (i < game->collectibles_numbers)
	{
		col = &game->collectibles[i];
		if (game->nb_frames % 35 == 0)
		{
			col->sprite_index++;
			col->sprite_index = col->sprite_index % 2;
		}
		i++;
	}
	update_player(game);
	if (game->bonus == 1)
		draw_enemy(game);
	mlx_put_image_to_window(game->mlx, game->win, game->screen, 0, 0);
	return (0);
}
