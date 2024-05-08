/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:13:51 by aroualid          #+#    #+#             */
/*   Updated: 2024/05/08 15:29:00 by aroualid         ###   ########.fr       */
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

