/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 22:03:53 by aroualid          #+#    #+#             */
/*   Updated: 2024/04/22 15:32:12 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_pars.h"

int	count_c(char **ptr, t_game *game)
{
	int		c;
	int		i;
	int		j;
	char	*str;

	j = 0;
	c = 0;
	i = 0;
	while(i < game->max_y)
	{
		str = ptr[i];
		while (str[j] != '\n')
		{
			if (str[j] ==  'C')
				c++;
			j++;
		}
		i++;
		j = 0;
	}
	return (c);
}

int	count_e(char **ptr, t_game *game)
{
	int		e;
	int		i;
	int		j;
	char	*str;

	j = 0;
	e = 0;
	i = 0;
	while(i < game->max_y)
	{
		str = ptr[i];
		while (str[j] != '\n')
		{
			if (str[j] ==  'E')
				e++;
			j++;
		}
		i++;
		j = 0;
	}
	return (e);
}

int	count_p(char **ptr, t_game *game)
{
	int		p;
	int		i;
	int		j;
	char	*str;

	j = 0;
	p = 0;
	i = 0;
	while(i < game->max_y)
	{
		str = ptr[i];
		while (str[j] != '\n')
		{
			if (str[j] ==  'P')
			{
				p++;
				game->pp_x = j;
				game->pp_y = i;
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (p);
}


int	count_element(char **file, t_game *game)
{
	int c;
	int	e;
	int	p;

	c = count_c(file, game);
	e = count_e(file, game);
	p = count_p(file, game);
	if (c >= 1 && e == 1 && p == 1
		&&(first_last_wall(file, game) == 1)
		&& (check_first_last_coll(file, game) == 1)
		&& check_good_carac(file, game) == 1)
	{
		printf("OUI\n");
		return (1);
	}
	else
	{
		printf("NON\n");
		return (0);
	}
}

int	count_element_ff(char **file, t_game *game)
{
	int c;
	int	e;
	int	p;

	c = count_c(file, game);
	e = count_e(file, game);
	p = count_p(file, game);
	if (c >= 1 || e == 1 || p == 1)
		return(0);
	else
		return(1);
}
