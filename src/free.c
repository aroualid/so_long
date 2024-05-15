/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 09:23:43 by aroualid          #+#    #+#             */
/*   Updated: 2024/05/15 09:26:34 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(t_game *game)
{
	int	i;
	
	if (!game)
		return ;
	i = 0;
	while (i < game->max_y)
	{
		if (game->map[i])
		{
			free(game->map[i]);
			game->map[i] = NULL;
			free(game->map_ok[i]);
			game->map_ok[i] = NULL;
		}
		i++;
	}
	free(game->map);
	free(game->map_ok);
}
