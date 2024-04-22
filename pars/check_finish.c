/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_finish.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:43:03 by aroualid          #+#    #+#             */
/*   Updated: 2024/04/22 15:34:23 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_pars.h"

int	first_last_wall(char **ptr, t_game *game)
{
	int		i;
	char	*first;
	char	*last;

	i = 0;
	first = ptr[0];
	last = ptr[game->max_y - 1];
	while (first[i] != '\n')
	{
		if (first[i] == '1')
			i++;
		else
			return (0);
	}
	i = 0;
	while (last[i] != '\n')
	{
		if (last[i] == '1')
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_first_last_coll(char **ptr, t_game *game)
{
	int		i;
	char	*str;

	i = 0;
	while (i < game->max_y)
	{
		str = ptr[i];
		if (str[0] == '1' && str[game->max_x - 1] == '1')
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_good_carac(char **ptr, t_game *game)
{
	int		i;
	char	*str;
	int		j;

	j = 0;
	i = 0;
	while (i < game->max_y)
	{
		str = ptr[i];
		while (j != game->max_x - 1)
		{
			if ((str[j] == '1') || (str[j] == '0') || (str[j] == 'P') ||
				(str[j] == 'C') || (str[j] == 'E'))
				j++;
			else
				return (0);
		}
		j = 0;
		i++;

	}
	printf ("YOUPI\n");
	return (1);
}

int	flood_fill(t_game *game, int x, int y, char *file)
{
    if (x < 0 || x >= game->max_x  || y < 0 || y >= game->max_y )
        return (0);
    if (game->map[y][x] == '1' || game->map[y][x] == 'X')
		return (0);
	game->map[y][x] = 'X';
    flood_fill(game, x + 1, y, file);
    flood_fill(game, x - 1, y, file);
    flood_fill(game, x, y + 1, file);
    flood_fill(game, x, y - 1, file);
    return (1);
}
