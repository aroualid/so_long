/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_finish.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:43:03 by aroualid          #+#    #+#             */
/*   Updated: 2024/04/19 16:10:59 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_pars.h"

int	first_last_wall(char *file, t_game *game)
{
	char	**ptr;
	int		i;
	char	*first;
	char	*last;

	i = 0;
	ptr = get_each_line(file, game);
	first = ptr[0];
	last = ptr[get_line(file) - 1];
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

int	check_first_last_coll(char *file, t_game *game)
{
	char	**ptr;
	int		i;
	char	*str;

	i = 0;
	ptr = get_each_line(file, game);
	while (i < get_line(file))
	{
		str = ptr[i];
		if (str[0] == '1' && str[get_len_line(file, game) - 1] == '1')
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_good_carac(char *file, t_game *game)
{
	char	**ptr;
	int		i;
	char	*str;
	int		j;

	j = 0;
	i = 0;
	ptr = get_each_line(file, game);
	while (i < get_line(file))
	{
		str = ptr[i];
		while (j != get_len_line(file, game) - 1)
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

int    flood_fill(t_game *map, int x, int y)
{
    if (x < 0 || x > map->map_x || y < 0 || y > map->map_y)
        return (1);
    if (map->map[y][x] == '1' || map->map[y][x] == 'c')
        return (1);
    else
        map->map[y][x] = 'c';
    flood_fill(map, x + 1, y);
    flood_fill(map, x - 1, y);
    flood_fill(map, x, y + 1);
    flood_fill(map, x, y - 1);
    return (0);
}
