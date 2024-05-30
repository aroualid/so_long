/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:13:51 by aroualid          #+#    #+#             */
/*   Updated: 2024/05/30 11:48:45 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_pars.h"

int	pars_bonus(int ac, char **av, t_game *game)
{
	if (ac == 2)
	{
		if (check_file (av[1]) == 0)
			return (ft_putstr_fd("ERROR\n", 2), 0);
		else if (check_file (av[1]) == 1
			&& get_len_line(av[1], game) != 0
			&& count_element_bonus(game->map, game) == 1)
		{
			flood_fill(game, game->pp_x, game->pp_y, av[1]);
			if (count_element_ff_bonus(game->map, game) == 0)
				return (ft_putstr_fd("ERROR\n", 2), 0);
		}
		else
			return (ft_putstr_fd("ERROR\n", 2), 0);
	}
	else
		return (ft_putstr_fd("ERROR\n", 2), 0);
	return (1);
}
