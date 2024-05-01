/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:23:30 by aroualid          #+#    #+#             */
/*   Updated: 2024/05/02 00:39:24 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "../includes/so_long.h"
# include "../pars/so_long_pars.h"
#include <stdint.h>

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
	while (i < img->width * 4)
	{
		j = -1;
		while (++j < img->height * 4)
		{
			if (j + y  < 0 || j + y >= 1080
				|| i + x < 0 || i + x >= 1920)
				continue ;
			color = ((int *)img->data)[(int)
				(j / 4) *img->width + (int)(i / 4)];
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
		mlx_loop_end(game->mlx);	
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

int	update_apply_move(t_game *game)
{
	t_player	*play;
	
	play = &game->player;
	game->nb_frames++;
	detect_key(game);
	draw_sprite(game, game->sprites[game->sprite_index], play->x , play->y);

	return (0);

}
int	update_player(t_game *game)
{
	t_player	*play;
	
	play = &game->player;
	game->nb_frames++;
	detect_key(game);
	draw_sprite(game, game->sprites[game->sprite_index], play->x , play->y);
	if (game->key_w || game->key_s || game->key_d || game->key_a)
	{
		game->sprites = game->correct_sprites;
		if (game->nb_frames % 32 == 0)
		{
			game->sprite_index++;
			game->sprite_index = game->sprite_index%6;
		}
	}
	if (game->key_w && play->y > 0)
		play->y--;
	if (game->key_a && play->x > 0)
	{
		game->sprites = game->reverse_sprites;
		play->x--;
	}
	if (game->key_s && play->y < 1080 - 200)
		play->y++;
	if (game->key_d && play->x < 1920 - 150)
	{
		game->sprites = game->correct_sprites;
		play->x++;
	}
	if (game->key_w == 0 && game->key_s == 0 && game->key_d == 0 && game->key_a == 0)
	{	
		game->sprites = game->sprites;
	}
	return (0);
}

int	update(t_game *game)
{
	t_collectible	*col;
	game->nb_frames++;
	clear_sprites(game);
	detect_key(game);
	draw_sprite(game, game->sprites_m[game->sprite_mechant], 1000, 500);

	for (int i = 0; i < game->collectibles_numbers; i++)
	{
		col = &game->collectibles[i];
		draw_sprite(game, col->fruit_sprites[col->sprite_index], col->x, col->y);
		if (game->nb_frames % 35 == 0)
		{
			col->sprite_index++;
			col->sprite_index = col->sprite_index%2;
		}
	}
	update_player(game);

	mlx_put_image_to_window(game->mlx, game->win, game->screen, 0, 0);
	if (game->nb_frames % 32 == 0)
	{
		game->sprite_mechant++;
		game->sprite_mechant = game->sprite_mechant%4;
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

t_img	**load_duck(t_game *game)
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
	game->correct_sprites = ptr;

	return (ptr);
}

t_img	**load_duck_reverse(t_game *game)
{
	t_img	**ptr;

	ptr = malloc(sizeof(t_img*) * 6);
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
	ptr = malloc(sizeof(t_img*) * 2);
	ptr[0] = load_sprite(game->mlx, "textures/duck_wait_1.xpm");
	ptr[1] = load_sprite(game->mlx, "textures/duck_wait_2.xpm");

	game->sprites_duck_wait = ptr;
	return (ptr);
}
t_img	**load_mechant(t_game *game)
{
	t_img	**ptr;

	ptr = malloc(sizeof(t_img*) * 4);
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

uint32_t    xorshift32(t_xorshift32_state *state)
{
    uint32_t    x;

    x = state->a;
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    return (state->a = x);
}


void	generate_random_fruit(t_game *game, int index)
{
	uint32_t	random;

	random = xorshift32(&game->rand) % 5;
	game->collectibles[index].x = xorshift32(&game->rand) % 1300 + 200;
	game->collectibles[index].y = xorshift32(&game->rand) % 600 + 200;
	game->collectibles[index].sprite_index = 0;
	game->collectibles[index].fruit_sprites = game->load_fruit[random];
}

int	main(int ac, char **av)
{
	t_game		game;
	int			i;
	void		*p;

	if (pars(ac, av) != 0)
	{
		i = 0;
		game = (t_game){0};
		p = malloc(1);
		game.rand.a = (uint32_t)(unsigned long) p;
		free(p);
		init_mlx_settings(&game);
		game.player.x = 500;
		game.player.y = 500;
		//game.test = load_sprite(game.mlx, (char *) game.sprites[game.sprite_index]);
		//if (!game.test)
		//	printf("AIRORE\n");
		
		load_fruit(&game);
		load_duck(&game);
		load_mechant(&game);
		load_duck_wait(&game);
		load_duck_reverse(&game);
		game.collectibles_numbers = 5;

		game.collectibles = malloc(sizeof(t_collectible) * game.collectibles_numbers);
		for (int i = 0; i < game.collectibles_numbers; i++)
			generate_random_fruit(&game, i);
		mlx_loop_hook(game.mlx, update, &game);
		mlx_hook(game.win, KeyPress, KeyPressMask, key_pressed, &game);
		mlx_hook(game.win, KeyRelease, KeyReleaseMask, key_released, &game);
		mlx_hook(game.win, DestroyNotify, 0, close_game, &game);
		mlx_loop(game.mlx);
	}
}
