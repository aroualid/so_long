/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:23:30 by aroualid          #+#    #+#             */
/*   Updated: 2024/04/29 11:21:16 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "../includes/so_long.h"
# include "../pars/so_long_pars.h"

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
	while (i < img->width)
	{
		j = -1;
		while (++j < img->height)
		{
			if (j + y  < 0 || j + y >= 1080
				|| i + x < 0 || i + x >= 1920)
				continue ;
			color = ((int *)img->data)[(int)
				(j ) *img->width + (int)(i )];
			if (color == 0xFF000000)
				continue ;
			((int *)game->screen->data)[(y + j )
				* game->screen->width + (x + i )] = color;
		}
		i++;
	}
}

int	close_game(t_game *game)
{
	mlx_loop_end(game->mlx);
	return (0);
}

int	key_pressed(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		game->key_esc = 1;
	if (keycode == 'w' || keycode == XK_Up)
		game->key_w = 1;
	if (keycode == 's' || keycode == XK_Down)
		game->key_s = 1;
	if (keycode == 'a' || keycode == XK_Left)
		game->key_a = 1;
	if (keycode == 'd' || keycode == XK_Right)
		game->key_d = 1;
	if (keycode == XK_space)
		game->key_space = 1;
	return (0);
}

int	key_released(int keycode, t_game *game)
{
	if (keycode == 'w' || keycode == XK_Up)
		game->key_w = 0;
	if (keycode == 's' || keycode == XK_Down)
		game->key_s = 0;
	if (keycode == 'a' || keycode == XK_Left)
		game->key_a = 0;
	if (keycode == 'd' || keycode == XK_Right)
		game->key_d = 0;
	if (keycode == XK_space)
		game->key_space = 0;
	return (0);
}

void	detect_key(t_game *game)
{

	if (game->key_esc)
		close_game(game);
}

int	update(t_game *game)
{
	detect_key(game);
	draw_sprite(game->mlx,game->test, 500 , 500);
	mlx_put_image_to_window(game->mlx, game->win, game->screen, 0, 0);
	return (0);
}

int	init_mlx_settings(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_putstr_fd("Error\n❌the mlx pointer is NULL❌\n", 2);
		return (-1);
	}
	game->win = mlx_new_window(game->mlx, 1920, 1080, "so_long");
	game->screen = mlx_new_image(game->mlx, 1920, 1080);
	return (0);
}


int	main(int ac, char **av)
{
	t_game		game;

	if (pars(ac, av) != 0)
	{
		game = (t_game){0};

		init_mlx_settings(&game);
		printf("%p\n", game.test);
		mlx_loop_hook(game.mlx, update, &game);
		mlx_hook(game.win, KeyPress, KeyPressMask, key_pressed, &game);
		mlx_hook(game.win, KeyRelease, KeyReleaseMask, key_released, &game);
		mlx_hook(game.win, DestroyNotify, 0, close_game, &game);
		mlx_loop(game.mlx);
	}
	else
		return (pars(ac, av));
}
