* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:42:31 by aroualid          #+#    #+#             */
/*   Updated: 2024/05/28 16:37:33 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_pars.h"

int	check_good_carac_bonus(char **ptr, t_game *game)
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
			if ((str[j] == '1') || (str[j] == '0') || (str[j] == 'P')
				|| (str[j] == 'C') || (str[j] == 'E' || (str[j] == '2')))
				j++;
			else
				return (0);
		}
		j = 0;
		i++;
	}
	return (1);
}

int	count_2(char **ptr, t_game *game)
{
	int		e;
	int		i;
	int		j;
	char	*str;

	j = 0;
	e = 0;
	i = 0;
	while (i < game->max_y)
	{
		str = ptr[i];
		while (str[j] != '\n')
		{
			if (str[j] == '2')
			{
				e++;
				game->ennemy.x = j;
				game->ennemy.y = i;
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (e);
}

int	count_2_ff(char **ptr, t_game *game)
{
	int		e;
	int		i;
	int		j;
	char	*str;

	j = 0;
	e = 0;
	i = 0;
	while (i < game->max_y)
	{
		str = ptr[i];
		while (str[j] != '\n')
		{
			if (str[j] == '2')
			{
				e++;
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (e);
}

int	count_element_bonus(char **file, t_game *game)
{
	int	c;
	int	e;
	int	p;
	int	n;

	n = count_2(file, game);
	c = count_c(file, game);
	e = count_e(file, game);
	p = count_p(file, game);
	if (c >= 1 && e == 1 && p == 1 && n == 1
		&& (first_last_wall(file, game) == 1)
		&& (check_first_last_coll(file, game) == 1)
		&& check_good_carac_bonus(file, game) == 1)
		return (1);
	else
		return (0);
}

int	count_element_ff_bonus(char **file, t_game *game)
{
	int	c;
	int	e;
	int	p;
	int	n;

	c = count_c_ff(file, game);
	e = count_e_ff(file, game);
	p = count_p_ff(file, game);
	n = count_2_ff(file, game);
	if (c >= 1 || e == 1 || p == 1 || n == 1)
		return (0);
	else
		return (1);
}
