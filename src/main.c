/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:23:30 by aroualid          #+#    #+#             */
/*   Updated: 2024/04/29 17:01:28 by aroualid         ###   ########.fr       */
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
	while (i < img->width * 5)
	{
		j = -1;
		while (++j < img->height * 5)
		{
			if (j + y  < 0 || j + y >= 1080
				|| i + x < 0 || i + x >= 1920)
				continue ;
			color = ((int *)img->data)[(int)
				(j / 5) *img->width + (int)(i / 5 )];
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

void	clear_sprites(t_game *game)
{
	int	i = 0;
	while (i < game->screen->width * game->screen->height)
	{
		((int *) game->screen->data)[i] = 0;
		i++;
	}
}
int	update(t_game *game)
{
	game->nb_frames++;
	clear_sprites(game);
	detect_key(game);
	draw_sprite(game, game->sprites[game->sprite_index], 1000 , 500);
	mlx_put_image_to_window(game->mlx, game->win, game->screen, 0, 0);
	if (game->nb_frames % 32 == 0)
	{
		game->sprite_index++;
		game->sprite_index = game->sprite_index%6;
	}
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

t_img	**load_loop(t_game *game)
{
	t_img	**ptr;

	ptr = malloc(sizeof(t_img*) * 6);
	ptr[0] = load_sprite(game->mlx, "textures/duck_1.xpm");
	ptr[1] = load_sprite(game->mlx, "textures/duck_2.xpm");
	ptr[2] = load_sprite(game->mlx, "textures/duck_3.xpm");
	ptr[3] = load_sprite(game->mlx, "textures/duck_4.xpm");
	ptr[4] = load_sprite(game->mlx, "textures/duck_5.xpm");
	ptr[5] = load_sprite(game->mlx, "textures/duck_6.xpm");

	game->sprites = ptr;
	return (ptr);
}

int	main(int ac, char **av)
{
	t_game		game;
	int			i;
	if (pars(ac, av) != 0)
	{
		i = 0;
		game = (t_game){0};
		init_mlx_settings(&game);
		//game.test = load_sprite(game.mlx, (char *) game.sprites[game.sprite_index]);
		//if (!game.test)
		//	printf("AIRORE\n");
		
		load_loop(&game);
		mlx_loop_hook(game.mlx, update, &game);
		mlx_hook(game.win, KeyPress, KeyPressMask, key_pressed, &game);
		mlx_hook(game.win, KeyRelease, KeyReleaseMask, key_released, &game);
		mlx_hook(game.win, DestroyNotify, 0, close_game, &game);
		mlx_loop(game.mlx);
	}
}
