/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:58:59 by aroualid          #+#    #+#             */
/*   Updated: 2024/05/28 13:22:20 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_pars.h"

void	free__map(char **ptr, t_game *game)
{
	int	i;

	i = 0;
	if (ptr != NULL)
	{
		while (i < game->max_y)
		{
			free(ptr[i]);
			ptr[i] = NULL;
			i++;
		}
		free(ptr);
	}
}

int	get_line(char *file, t_game *game)
{
	char	*str;
	int		infile;
	int		i;

	i = 0;
	infile = open(file, O_RDONLY);
	str = get_next_line(infile);
	while (str)
	{
		i++;
		free (str);
		str = get_next_line(infile);
	}
	close (infile);
	free(str);
	game->max_y = i;
	return (i);
}

char	**get_each_line(char *file, t_game *game)
{
	char	**ptr;
	int		j;
	char	*str;
	int		infile;

	infile = open(file, O_RDONLY);
	str = get_next_line(infile);
	j = 0;
	ptr = ft_calloc(sizeof(char **), game->max_y);
	game->map = ft_calloc(sizeof(char **), game->max_y);
	game->map_ok = ft_calloc(sizeof(char **), game->max_y);
	while (j < game->max_y)
	{
		ptr[j] = ft_strdup(str);
		game->map[j] = ft_strdup(str);
		game->map_ok[j] = ft_strdup(str);
		free(str);
		str = get_next_line(infile);
		j++;
	}
	close (infile);
	return (ptr);
}

int	get_len_line(char *file, t_game *game)
{
	int		res;
	int		i;
	char	**ptr;
	int		j;
	int		first_res;

	first_res = 0;
	res = 0;
	i = get_line(file, game);
	ptr = get_each_line(file, game);
	first_res = ft_strlen(ptr[0]) - 1;
	j = 1;
	while (j < i)
	{
		res = ft_strlen(ptr[j]) - 1;
		if (res == first_res)
			j++;
		else
			return (0);
	}
	game->max_x = res;
	free__map(ptr, game);
	return (1);
}
