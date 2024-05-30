/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:34:32 by aroualid          #+#    #+#             */
/*   Updated: 2024/05/30 14:02:59 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_pars.h"
#include "../includes/so_long.h"

int	count_c_ff(char **ptr, t_game *game)
{
	int		c;
	int		i;
	int		j;
	char	*str;

	j = 0;
	c = 0;
	i = 0;
	while (i < game->max_y)
	{
		str = ptr[i];
		while (str[j] != '\n')
		{
			if (str[j] == 'C')
				c++;
			j++;
		}
		i++;
		j = 0;
	}
	return (c);
}

int	count_p_ff(char **ptr, t_game *game)
{
	int		p;
	int		i;
	int		j;
	char	*str;

	j = 0;
	p = 0;
	i = 0;
	while (i < game->max_y)
	{
		str = ptr[i];
		while (str[j] != '\n')
		{
			if (str[j] == 'P')
			{
				p++;
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (p);
}

int	extension(char *av2)
{
	int	i;

	i = ft_strlen(av2);
	if (i > 4)
	{
		if (ft_strncmp(av2 + i - 4, ".ber", 4) != 0)
			return (0);
		else
		{
			if (av2[i - 5] == '/')
				return (0);
			return (1);
		}
		return (1);
	}
	else if (i <= 4)
		return (0);
	return (0);
}

int	check_file(char *av2, t_game *game)
{
	if (extension (av2) == 1)
	{
		game->i = open(av2, O_RDONLY);
		game->j = open(av2, O_DIRECTORY);
		if (game->i != -1 && game->j == -1)
			return (1);

		else
			return (0);
	}
	else
		return (0);
}

int	pars(int ac, char **av, t_game *game)
{
	if (ac == 2)
	{
		game->k = check_file(av[1], game);
		if (game->k == 0)
			return (ft_putstr_fd("ERROR\n", 2), 0);
		else if (game->k == 1
			&& get_len_line(av[1], game) != 0
			&& count_element(game->map, game) == 1)
		{
			flood_fill(game, game->pp_x, game->pp_y, av[1]);
			if (count_element_ff(game->map, game) == 0)
				return (ft_putstr_fd("ERROR\n", 2), 0);
		}
		else
			return (ft_putstr_fd("ERROR\n", 2), 0);
	}
	else
		return (ft_putstr_fd("ERROR\n", 2), 0);
	return (1);
}
